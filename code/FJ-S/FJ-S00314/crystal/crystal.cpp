#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
bool A=1,B=1;
bool p[20];
int ans=0;
bool check(long long mx){
	long long nd=0;
	for(int i=1;i<=n;i++){
		if(p[i]){
			nd+=mx-a[i];
		}
	}
	return (bool)(nd<=m);
}
void dfs(int i,bool num,int cho,long long mx){
	p[i]=num;
	if(i==n){
		if(mx==-0x3f3f3f3f) return ;
		if(check(mx)){
			ans=max(cho,ans);
		}
		return ;
	}
	dfs(i+1,0,cho,mx);
	dfs(i+1,1,cho+1,max(mx,a[i+1]));
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) A=0;
	}
	sort(a+1,a+1+n);
	if(A){
		for(long long i=n;i>=1;i--){
			if(i*(i-1)/2<=m){
				cout<<i;
				return 0;
			}
		}
		return 0;
	}
	long long cha=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			B=0;break;
		}
	}
	if(B){
		for(long long i=n;i>=1;i--){
			if((i*a[i]-(a[1]+a[i])*i/2)<=m){
				cout<<i;
				return 0;
			}
		}
	}
	if(n<=16){
		dfs(0,0,0,-0x3f3f3f3f);
		cout<<ans;
		return 0;
	}
	return 0;
} 
