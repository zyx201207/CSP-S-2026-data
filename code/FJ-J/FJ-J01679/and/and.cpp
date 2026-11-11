#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int f1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(!ch1(a[i])) f1=1;
	}
	if(n==m){
		int ss=a[1];
		for(int i=2;i<=n;i++){
			ss&=a[i];
		}
		cout<<ss<<endl;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n]<<endl;
		return 0;
	}
	if(m==2&&n<=2000){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ma=max(ma,a[i]&a[j]);
				}
			}
		}
		cout<<ma<<endl;
	}
	if(n<=20){
		if(m==1){
			sort(a+1,a+n+1);
			cout<<a[n]<<endl;
		}
		if(m==2){
			int ma=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						ma=max(ma,a[i]&a[j]);	
					}
				}
			}
		}
		if(m==3){
			int ma=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						if(i!=j&&i!=k&&j!=k){
							ma=max(ma,a[i]&a[j]&a[k]);
						}
					}
				}
			}
			cout<<ma<<endl;
		}
		if(m==4){
			int ma=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						for(int z=1;z<=n;z++){
							if(i!=j&&i!=k&&i!=z&&j!=k&&j!=z&&k!=z){
								ma=max(ma,a[i]&a[j]&a[k]&a[z]);
							}
						}
					}
				}
			}
			cout<<ma<<endl;
		}
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[m]<<endl;
	}
	return 0;
} 
