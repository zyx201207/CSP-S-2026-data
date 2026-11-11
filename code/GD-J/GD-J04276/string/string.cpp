#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fo(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return;
}
void sol(){
	int n,move;
	ll a[200001]={0},ans,t1=0,t2;
	char c[200001];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],a[i]+=a[i-1];
	t2=a[n];
	for(int i=0,j=n;i<j&&t1<=t2;){
		if(t1==t2||i==j)break;
		if(c[i]!=c[j])
			ans+=min(a[i]-t1,t2-a[j-1])/*,cout<<min(a[i]-t1,t2-a[j-1])<<c[i]<<c[j]<<'\n'*/;
		move=min(a[i]-t1,t2-a[j-1]);
		if(a[i]-t1==move)i++;
		if(t2-a[j-1]==move)j--;
		t1+=move,t2-=move;
	}
	cout<<ans;
	return;
}
int main(){
	fo();
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		sol();
	}
	return 0;
}
