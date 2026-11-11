#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N=2e5+5;
int t[32];
bool b[N];
ll a[N];
int y[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		y[i]=x;
		b[x]=1;
		int num=0;
		while(x!=0){
			t[num++]+=x%2;
			a[i]=a[i]*10+x%2;
			x/=2;
		}
	}
	int ans=0;
	for(int i=n;i>=1;i--){
		int num=0;
		bool f=1;
		while(a[i]!=0){
			if(a[i]%10==1){
				if(t[num++]<m){
					f=0;
					break;
				}
			}
			a[i]/=10;
		}
		if(f==1){
			ans=max(ans,y[i]);
		}
	}
	cout<<ans;
	return 0;
} 
