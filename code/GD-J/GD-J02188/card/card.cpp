#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[500010],lst[500010],k;
bool vis[500010];
class Line{
	public:
		int l,r;
}L[500010];
void addl(int l,int r){
	if(l==0)return;
	L[++k]={l,r};
}
bool check1(int n){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1])return false;
	}
	return true;
}
void solve1(int n){
	for(int i=1;i<=n;i++)lst[a[i]]=i;
	for(int i=1;i<=m;i++)cout<<lst[i]<<' ';
	return;
}
void solve2(int n){
	for(int i=1;i<=n;i++){
		addl(lst[a[i]],i);
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++)cout<<n<<' ';
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check1(n))solve1(n);
	else solve2(n);
	return 0;
}
//zui hou yi ti bu hui zuo,wo hao cai!
//I want to listen to music 
