#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
struct st{
	int t;
	int id;
}b[200005];
bool cmp1(st x,st y){
	return x.t>y.t;
}
void m_1(){
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
}
void m_2(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
}
void m_n(){
	ans=a[1];
	for(int i=1;i<n;i++){
		ans=ans&a[i];
	}
}
void zj(){
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int ai=a[i];
		b[i].id=i;
		while(ai>0){
			if(ai%2==1){
				b[i].t++;
			}
			ai/=2;
		}
	}
	sort(b+1,b+n+1,cmp1);
	ans=1e18;
	for(int i=1;i<=m;i++){
		ans=min(ans,a[b[i].id]);
	}
}
void _and(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		m_1();
	}else if(m==2){
		m_2();
	}else if(m==n){
		m_n();
	}else{
		zj();
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--){
		_and();
	}
	return 0;
}
