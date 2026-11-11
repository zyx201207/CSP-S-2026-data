#include<bits/stdc++.h>
using namespace std;
#define int long long
void to2(int a,int &cnt,string &res){
	while(a){
		cnt+=(a&1);
		res=(char(a&1))+res;
		a>>=1;
	}
	return ;
}
int n,m,ans;
struct node {
	int x,cnt;
	string x2;
}d[200005];
bool cmp(node a,node b){
	if(a.cnt!=b.cnt) return a.cnt>b.cnt;
	else return a.x2<b.x2;
}
signed main(){
    freopen("and.in","r",stdin); freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>d[i].x;
		to2(d[i].x,d[i].cnt,d[i].x2);
	}
	sort(d,d+n,cmp);
	ans=d[0].x;
	for(int i=1;i<m;i++){
		ans=(ans&d[i].x);
	}
	cout<<ans;
	return 0;
}
