#include <bits/stdc++.h>
using namespace std;
long long int b[1000000]={0};
int main(){
	freopen("crystal3.in","r",stdin);
    freopen("crystal7.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    long long int a[1000000]={0};
    int minx1,minx2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
			if(a[i]>=a[j]){
				swap(a[i],a[j]);
			}
		}
    }
    for(int i=1;i<=n;i++){
        if(i>=2){
            minx1=a[i];
            minx2=a[i-1];
            b[i-1]=minx1-minx2;
        }
    }
    int f=0;
    for(int i=1;i<=n-1;i++){
		f+=b[i]*i;
        if(f>m){
            break;
        }
        for(int j=1;j<=i;j++){
            a[j]+=b[i];
        }
        
    }
    int num=0;
    int g=a[1];
    for(int i=1;i<=n;i++){
        if(a[i]==g){
            num++;
        }
    }
    cout<<num;
    return 0;
}
