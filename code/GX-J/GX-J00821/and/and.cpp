#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10000]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ma=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long ss=a[i]&a[j];
				ma=max(ma,ss);
			}
		}
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+2;k<=n;k++){
					long long ss=a[i]&a[j];
					long long sb=ss&a[k];
					ma=max(ma,sb);
				}
				
			}
		}
		
	}
	cout<<ma;
	return 0;
}
