#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[500050],ans[10000];
int 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>a[i];
	}
	if(n==2){
		if(a[1]!=a[2]){
			if(m==1){
				cout<<1;
				return 0;
			}else{
				cout<<1<<" "<<2;
				return 0;
			}
		}else{
			cout<<1;
			return 0;
		}
	}else if(n==3){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans[1]++;
			}else if(a[i]==2){
				ans[2]++;
			}
		}
		if(m==1){
			if(a[1]==1){
				cout<<1;
				return 0;
			}else if(a[1]==3){
				cout<<3;
				return 0;
			}else{
				cout<<2;
				return 0;
			}
		}else{
			if(a[1]==1){
				if(a[2]==a[3]){
					cout<<1<<" "<<1;
				}else{
					cout<<1<<" "<<2;
				}
			}else if(a[1]==2){
				if(a[1]==1&&a[2]==1){
					cout<<2<<" "<<2;
					return 0;
				}else if(a[1]==1&&a[3]==1){
					cout<<2<<" "<<1;
					return 0;
				}else{
					cout<<2<<" "<<2;
					return 0;
				}
			}
		}
	}
	return 0;
}
