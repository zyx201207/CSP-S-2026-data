#include<bits/stdc++.h>
using namespace std;
const int MAXN=200002;
int n,m;
int a[MAXN];
bool lg[MAXN];
int maxn=-1;
int n_m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i*i<=n;i++){
		lg[i*i]=true;
	}
	bool ok_a=true,ok_b=true;
	if(!lg[n])ok_b=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)n_m=a[i];
		else n_m&=a[i];
		maxn=max(maxn,a[i]);
		if((!ok_a)||!lg[a[i]+1])ok_a=false;
		if(!ok_b)continue;
		if(a[i]!=i-1){
			ok_b=false;
		}
	}
	// A
	if(ok_a){
		cout<<1<<'\n';
	}else if(m==1){
		cout<<maxn<<'\n';
	}else if(m==n){
		cout<<n_m<<'\n';
	}
	return 0;
}
