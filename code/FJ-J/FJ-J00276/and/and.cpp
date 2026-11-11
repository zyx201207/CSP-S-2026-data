#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=INT_MAX;
int t;
int p[200005];
int f1(int x){
	int cnt=0;
	int xx=x;
	while(xx){
		cnt+=xx%2;
		xx/=2;
	}
	return cnt;
}
int f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]!=i-1){
			f=1;
		}
	}
	if(!f){
		cout<<n-m;
		return 0;
	}
	sort(p+1,p+1+n,[](int x,int y){
		return f1(x)>f1(y);
	});
	for(int i=1;i<=m;i++){
		ans&=p[i];
	}
	cout<<ans;
	return 0;
}

