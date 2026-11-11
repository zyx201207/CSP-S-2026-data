#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ma=INT_MIN;
		for(int i=1;i<=n;i++){
			if(a[i]>ma)ma=a[i];
		}
		cout<<ma;
	}else if(m==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=(cnt&a[i]);
		}
		cout<<cnt;
	}else if(m==2){
		int ma=INT_MAX;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>ma)ma=(a[i]&a[j]);
			}
		}
		cout<<ma;
	}else if(m=n-1){
		int ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int h=k+1;h<=n;h++){
						for(int l=h+1;l<=n;l++){
							if((a[i]&a[j]&a[k]&a[h]&a[l])>ma)ma=(a[i]&a[j]&a[k]&a[h]&a[l]);
						}
					}
				}
			}
		}
		cout<<ma;
	}else{
		cout<<0;
	}
	return 0;
}
