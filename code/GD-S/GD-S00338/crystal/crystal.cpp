#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int n;
ll m,a[maxn],s[maxn];
bool chk(int x){
	for(int i=x;i<=n;i++) if(a[i]*x-(s[i]-s[i-x])<=m) return true;
	return false; 
}
void Doru(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	} 
	cout<<l<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Doru();
	return 0;
}

