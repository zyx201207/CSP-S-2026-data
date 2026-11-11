#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
int mx,n,m;
struct aaa{
	int val;
	int yi;
};
aaa ans[N];
int zhao(int x){
	int ans=1;
	while(x&=x-1) ans++;
	return ans;
}
bool cmp(aaa A,aaa B){
	if(A.yi==B.yi) return A.val>B.val;
	return A.yi>B.yi;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>ans[i].val;
		ans[i].yi=zhao(ans[i].val);
	}
	sort(ans+1,ans+n+1,cmp);
	mx=ans[1].val;
	for(int i=2;i<=m;i++) mx&=ans[i].val;
	cout<<mx;
}