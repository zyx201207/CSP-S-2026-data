#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],zd,b[1000000];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
		int z;
		z=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>z){
				z=a[i];
			}
		}
        cout<<z;
        return 0;
    }
    if(n==m){
		for(int i=2;i<=n;i++){
			zd=a[i]&a[i-1];
		}
		cout<<zd;
			return 0;
		}
    for(int i=2;i<=m;i++){
        b[i]=a[i]&a[i-1];
        zd=b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
			for(int t=2;t<=m;t++){
				if(i!=j){
				b[i]=a[i]&a[j];
			    }
			}
            if(i!=j && b[i]>zd){
               zd=b[i];
            }
        }
    }
    cout<<zd;
    return 0;
}
