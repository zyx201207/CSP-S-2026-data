#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+5,M=3e5+5;
int las[M];
int n,m,a[N],tmp=0;
int ans[M],cnt[M];
bool flag=1; //special case A
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(i>1)if(a[i]<a[i-1])flag=0;
	}
	for(int i=n;i>=1;i--){
		if(!las[a[i]]){
			tmp++;
			las[a[i]]=i;
			if(tmp==m)break;
		}
	}
	if(flag){
		for(int i=1;i<=m;i++)cout<<las[i]<<" ";
		return 0;
	}
	for(int i=1;i<=m;i++){
		int pos=las[i];
		vector<int> vec;
		while(pos<=n){
			vec.push_back(a[pos]);
			pos++;
			if(las[a[pos]]>pos)pos=las[a[pos]];
		}
		for(int j=0;j<vec.size();j++){
			ans[vec[j]]+=cnt[i];
		}
		vec.clear();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
