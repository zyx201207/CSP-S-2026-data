#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int ans[N],a[N],b[N];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof ans);
	memset(b,0,sizeof b);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>0;i--){
		if(b[a[i]]){
			while(!v.empty()){
				if(v.back()==a[i]) break;
				b[v.back()]=0;
				v.pop_back();
			}
		}
		else{
			v.push_back(a[i]);
			b[a[i]]=1;
		}
		for(int j=0;j<v.size();j++){
			ans[v[j]]++;	
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
