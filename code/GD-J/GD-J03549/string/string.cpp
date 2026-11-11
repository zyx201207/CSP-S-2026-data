#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s;
vector<pair<char,int>> v,h,t,ch,ct;
vector<int> cp;
map<int,bool> mp;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;char c;
		cin>>a>>c;
		s+=a;
		if(v.size()>0&&v[v.size()-1].first==c) v[v.size()-1].second+=a;
		else v.push_back({c,a});
	}
	int ls=0;
	for(int i=0;i<v.size();i++){
		bool fx=ls+ls<s;
		ls+=v[i].second;
		bool fy=ls+ls<s;
		if(fx^fy){
			h.push_back({v[i].first,s/2-ls+v[i].second});
			if(ls-s/2-(s&1)!=0) t.push_back({v[i].first,ls-s/2-(s&1)});
		}
		else if(fx) h.push_back(v[i]);
		else t.push_back(v[i]);
	}
	ls=0;
	for(int i=0;i<h.size();i++) cp.push_back(ls+=h[i].second);
	for(int i=0;i<t.size();i++) cp.push_back(ls-=t[i].second);
	sort(cp.begin(),cp.end());
	cp.erase(unique(cp.begin(),cp.end()),cp.end());
	int id=1,d=0;
	for(int i=0;i<h.size();i++){
		ls+=h[i].second;
		ch.push_back(h[i]);
		while(ls>cp[id]&&ls-h[i].second<cp[id]){
			auto chi=ch[i+d];ch.pop_back();
			ch.push_back({chi.first,cp[id]-ls+chi.second});
			ch.push_back({chi.first,ls-cp[id]});
			id++,d++;
		}
	}
	id--,d=0;
	for(int i=0;i<t.size();i++){
		ls-=t[i].second;
		ct.push_back(t[i]);
		while(ls<cp[id]&&ls+t[i].second>cp[id]){
			auto cti=ct[i+d];
			ct.push_back({cti.first,ls+t[i].second-cp[id]});
			ct.push_back({cti.first,cp[id]-ls});
			id--,d++;
		}
	}
	int res=0;
	for(int i=0;i<ch.size();i++)
		if(ch[i].first!=ct[ct.size()-i-1].first)
			res+=ch[i].second;
	cout<<res<<endl;
	return 0;
}
