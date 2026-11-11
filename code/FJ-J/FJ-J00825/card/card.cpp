#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int n,m;
int a[500010];
vector<int> v[500010];
int s[300010],f;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) if(a[i]<a[i-1]) f=1;
	if(f==0){
		for(int i=1;i<=n;i++){
			s[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			s[i]=s[i]+s[i-1];
			cout<<s[i]<<" ";
		}
		return 0;
	}
	v[a[n]].push_back(a[n]);
	s[a[n]]=1;
	for(int i=n-1;i>=1;i--){
		if(v[a[i]].size()==0){
			v[a[i]].push_back(a[i]);
			for(int j=0;j<v[a[i+1]].size();j++) v[a[i]].push_back(v[a[i+1]][j]);
		}
		for(int j=0;j<v[a[i]].size();j++) s[v[a[i]][j]]++;
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<v[i].size();j++){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}


