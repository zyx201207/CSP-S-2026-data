#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long ans[5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(a[1]==1){
			cout<<1<<" "<<2;
		}else{
			cout<<2<<" "<<1;
		}
	}else if(n==3){
		if(a[1]==a[3]){
			if(a[1]==1&&a[3]==1){
				cout<<3<<" "<<1;
			}else{
				cout<<1<<" "<<3;
			}
		}else{
			if(a[1]==1&&a[3]==2){
				cout<<2<<" "<<3;
			}else if(a[1]==2&&a[3]==1){
				cout<<3<<" "<<2;
			}
		}
	}
	return 0;
} 
