#include<bits/stdc++.h>
using namespace std;
const int M=5e5;
int a[M];
int n,cnt;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]>0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=n;k++){
					if(a[i]+j==a[k]){
						m=m-j;
						cnt++;
						break;
					} 
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=n;j>=1;j--){
				if(a[i]==a[j]&&i!=j){
					cnt++;
					break;
				}
			}
		} 
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				for(int k=1;k<=n;k++){
					if(a[i]+j==a[k]){
						m=m-j;
						cnt++;
						break;
					} 
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
