#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int a[maxn],maxa=0;
bool w[maxn];
int n,m;
void solve(int x,int num){
	if(x<1){
		maxa=max(maxa,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(w[i]) continue;
		w[i]=true;
		solve(x-1,num&a[i]);
		w[i]=false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		w[i]=false;
	}
	sort(a+1,a+1+n);
	if(n<=2000){
		if(m==n){
			int ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=n;i++){
			w[i]=true;
			solve(m-1,a[i]);
			w[i]=false;
		}
		cout<<maxa;
	}else{
		int ans=a[n];
		for(int i=1;i<m;i++) ans&=a[n-i];
		cout<<ans;
	}
}
