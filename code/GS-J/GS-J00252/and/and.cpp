#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,mx=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        if(i==1) ans=a[i];
        else ans=ans&a[i];
    }
    if(m==1) cout<<mx;
    else if(m==n){
        cout<<ans;
    }
    else{
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    int num=a[i]&a[j];
                    if(num>maxn){
                        maxn=num;
                    }
            }
        }
        cout<<maxn;
    }
	return 0;
}

