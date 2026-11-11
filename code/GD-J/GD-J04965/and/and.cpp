#include<bits/stdc++.h>
using namespace std;
#define int long long
bool num[200100][40];
void ejz(int x,int d){
	int c=1;
	while(x){
		num[d][c++]=x%2;
		x/=2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0,cnt=1,mx=0,mn=1e9,fg=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		mx=max(mx,x);
		if(x<mn){
			mn=x;
			fg=i;
		}
		ejz(x,cnt);
		cnt++;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			for(int o=1;o<=30;o++){
				num[1][o]&=num[i][o];
			}
		}
		int temp=1;
		for(int i=1;i<=30;i++){
			ans+=temp*num[1][i];
			temp*=2;
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=2;i<=n;i++){
			for(int o=1;o<=30;o++){
				if(i!=fg){
					num[1][o]&=num[i][o];
				}
			}
		}
		int temp=1;
		for(int i=1;i<=30;i++){
			ans+=temp*num[1][i];
			temp*=2;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
