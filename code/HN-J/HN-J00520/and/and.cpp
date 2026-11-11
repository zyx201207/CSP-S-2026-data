#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
typedef long long ll;
ll n,m,ans=-114514,a[maxn],mp;
bool cmp(int x,int y){ return x>y;}
//void dfs(int p,int q){
//	if (p==1||q==n-1) {
//		ans=a[q];
//		return ;
//	}
//	a[0]
//	for (auto t:a) {dfs(p-1,q+1)};
//	if ()
//} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[0];
	int mp=a[0];
	for (ll i=1;i<n;i++){
		cin>>a[i];
		mp&=a[i];
	}
	if (m==n){
		cout<<mp;
		return 0;
	}
	if (m==2){
		for (ll i=0;i<n;i++){
			for (ll j=i;j<n;j++){
				ll d=a[i]&a[j];
				//cout<<d<<endl;
				if (d>ans) ans=d;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	sort(a,a+n,cmp);
	if (m==1){
		cout<<a[0];
		return 0;
	}
//	if (n<=20){
//		dfs(m,0);//
//	}
	//for (ll i=0;i<n;i++) cout<<a[i]<<" ";
	ans=a[0]; 
	for (ll j=1;j<m;j++) ans&=a[j];
	cout<<ans;
//	for (int k=1;k<=255;k++) cout<<(11&k) <<" ";
	return 0;
}//1919810 114514
