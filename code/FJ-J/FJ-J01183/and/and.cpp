#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,cnt1;
	string jz="";
};
node a[200010];
void fun(node t){
	if (t.x==0) t.jz="0";
	while (t.x){
		t.jz+=char(t.x%2+'0');
		t.x/=2;
	}
	string ss="";
	for (int i=t.jz.size()-1;i>=0;i--) ss+=t.jz[i];
	t.jz=ss;
	for (int i=0;i<t.jz.size();i++){
		if (t.jz[i]=='1') t.cnt1++;
	}
}
bool cmp(node x,node y){
	if (x.cnt1!=y.cnt1) return x.cnt1>y.cnt1;
	else return x.x>y.x;
}
int n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i].x;
		fun(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].x;
	for (int i=2;i<=m;i++) ans&=a[i].x;
	cout<<ans<<"\n";
	return 0;
}
