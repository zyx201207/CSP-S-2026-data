#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,sum,l;
vector<ll> a(5e5+10),b(5e5+10);

bool ck,cl;
bool check(){
	for(int i=1;i<=n;i++){
		if(c[i])return 0;
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;l=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
		vector<bool> c(5e5+10,1);
		c[i]=0;
		while(1){
			for(int j=1;j<=n;j++){
				if(c[j]==0)continue;
				if(a[j]==a[i]){
					c[j]=-1;
					continue;
				}
			}
			c[i]=0;
			if(check())break;
		}
		
	}
	return 0;
} 
