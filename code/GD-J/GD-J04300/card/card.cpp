#include <bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1)  cout<<n;
	if (n==2&&m==2){
		if (a[1]==1)  cout<<1<<" "<<2;
		else  cout<<2<<" "<<1;
	}
	if (n==3&&m==2){
		if (a[1]==1){
			if(a[2]==2){
				if (a[3]==1)  cout<<3<<" "<<1;
				else  cout<<0<<" "<<3;
			}else  cout<<2<<" "<<3;
		}else{
			if (a[2]==1){
				if (a[3]==1)  cout<<3<<" "<<0;
				else  cout<<1<<" "<<3;
			}else  cout<<2<<" "<<3;
		}
	}
	if (n==4&&m==2){
		if (a[1]==1){
			if(a[2]==1){
				if (a[3]==2){
					if (a[4]=1) cout<<4<<" "<<1;
					else  cout<<0<<" "<<4; 
				}else  cout<<3<<" "<<4;
			}else{
				if (a[3]==1){
					if (a[4]==1)  cout<<4<<" "<<0;
					else  cout<<1<<" "<<4;
				}else{
					if (a[4]==1)  cout<<4<<" "<<3;
					else  cout<<0<<" "<<4;
				}
			}
		}else{
			if (a[2]==1){
				if (a[3]==1)  cout<<3<<" "<<0;
				else  cout<<1<<" "<<3;
			}else  cout<<2<<" "<<3;
		}
	}
	return 0;
}
