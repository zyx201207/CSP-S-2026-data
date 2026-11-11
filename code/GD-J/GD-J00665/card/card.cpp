#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ls[300005],ans[300005];
bool f[300005];
vector<int>vt;
vector<pair<int,int> >c;
vector<vector<pair<int,int> >::iterator>z;
bool fn(pair<int,int> p1,pair<int,int> p2){
	if(p1.first==p2.first){
		return p1.second>p2.second;
	}
	return p1.first<p2.first;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(f[a[i]]){
			c.push_back({ls[a[i]],i});
		}
		f[a[i]]=true;
		ls[a[i]]=i;
	}
	sort(c.begin(),c.end(),fn);
	for(vector<pair<int,int> >::iterator it=c.begin();it!=c.end()-1;it++){
		int l=it->first,l1=(it+1)->first;
		if(l==l1){
			z.push_back(it);
		}
	}
	for(auto i:z){
		c.erase(i);
	}
	for(int j=1;j<=n;j++){
		memset(f,0,sizeof(f));
		int la=j;
		for(auto k:c){
			int l=k.first,r=k.second;
			if(l>=la){
				for(int q=la;q<l;q++){
					if(!f[a[q]]){
						f[a[q]]=true;
						vt.push_back(a[q]);
					}
				}
				la=r;
			}
		}
		for(int i:vt){
			ans[i]++;
		}
		for(int i=la;i<=n;i++){
			if(!f[a[i]]){
				f[a[i]]=true;
				ans[a[i]]++;
			}
		}
		vt.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
