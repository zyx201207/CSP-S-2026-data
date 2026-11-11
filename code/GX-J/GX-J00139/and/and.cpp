#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
	int n,m;
	cin>>n>>m;
	long long maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    long long maxs=-1;
    int ai,aj;
    int num=maxs;
    long long minn=1e17;
    long long yu=1;
    if(m==1){
        cout<<maxn;
        return 0;
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            minn=min(minn,a[i]);
        }
        for(int i=1;i<=n;i++){
            if(a[i]==minn) a[i]=1048575;
        }
        for(int i=1;i<=n;i++){
            yu=yu&a[i];
        }
        cout<<yu;
        return 0;
    }
    else if(m==n){
        for(int i=1;i<=n;i++){
            yu=yu&a[i];
        }
        cout<<yu;
        return 0;
    }
    else{
        while(m>0){
            m--;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    num=maxs;
                    maxs=max(maxs,a[i]&a[j]);
                    if(maxs>=num){
                        ai=i;
                        aj=j;
                    }
                }
            }
            a[ai]=0;
            a[aj]=0;
        }
        cout<<maxs;
        return 0;
    }

}
