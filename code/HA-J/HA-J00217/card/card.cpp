#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e5+5;
int n,m;
int a[N];
int lst[N],fis[N],las[N];
int ans[N],pos[N];
bool cmp(int a,int b){
	return lst[a]>lst[b];
}
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=m;++i){
		pos[i]=i;
	}
	for(int i=1;i<=n;++i){
		las[i]=lst[a[i]];
		lst[a[i]]=i;
		if(!fis[a[i]])fis[a[i]]=i;
	}
	
	sort(pos+1,pos+m+1,cmp);
	int last=n;
	for(int i=1;i<=m;++i){
		int x=lst[pos[i]];
		//cout << pos[i] << " " << x << '\n';
		int res=x;
		if(x>last){
			res=res-last;
		}
		ans[pos[i]]=res;
		if(las[x]!=0)last=min(last,las[x]);
		//cout << last << " 111 " << x << '\n';
		
	}
	
	for(int i=1;i<=m;++i){
		cout << lst[i] << " ";
	}
	
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _T=1;//cin >> _T;
	while(_T--){
		solve();
	}
	return 0;
}
