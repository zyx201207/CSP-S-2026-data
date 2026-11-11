#include<bits/stdc++.h>
using namespace std;
int n;
long long a,ans;
char c;
vector<pair<long long,char> > v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		v.push_back({a,c});
	}
	while(v.size()>1){
		int k=v.size()-1;
		auto t1=v[0],t2=v[k];
		if(v[0].second==v[k].second){
			if(v[0].first==v[k].first){
				v.erase(v.begin());
				v.erase(v.end()-1);
			}
			else if(v[0].first<v[k].first){
				v[k].first-=v[0].first;
				v.erase(v.begin());
			}
			else{
				v[0].first-=v[k].first;
				v.erase(v.end()-1);
			}	
		}
		else{
			if(v[0].first<v[k].first){
				ans+=v[0].first;
				v[k].first-=v[0].first;
				v.erase(v.begin());
			}
			else{
				ans+=v[k].first;
				v[0].first-=v[k].first;
				v.erase(v.end()-1);
			}
		}
	}
	cout<<ans;
}
