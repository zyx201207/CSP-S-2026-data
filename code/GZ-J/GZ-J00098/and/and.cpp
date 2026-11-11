//毕节七星关东辰实验学校 刘杰 GZ-J00098
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<string> p;

int cnt[31];vector<int> ok[31];

string tostr(int t,int h){
	string hh="";
	for(int i=30;i>=0;i--){
		hh+=(((h>>i)&1ll)+'0');
		if((h>>i)&1ll==1){
			cnt[i]++;ok[i].push_back(t);
		}
	}
	return hh;
}

string totr(int h){
	string hh="";
	for(int i=30;i>=0;i--){
		hh+=(((h>>i)&1ll)+'0');
	}
	return hh;
}

int toint(string k){
	int hh=0;
	for(int i=0;i<k.size();i++){
		if(k[i]=='1'){
			hh|=(1ll<<(30-i));
		}
	}
	return hh;
}

bool cmp(string a,string b){
	return a>b;
}

const int MX=2e5+10;
int pap[MX];bool in[MX];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		int u;cin>>u;
		tostr(i,u);
		pap[i]=u;
	}
	for(int i=30;i>=0;i--){
		for(int j=0;j<ok[i].size();j++){
			if(!in[ok[i][j]]){
				in[ok[i][j]]=1;
				p.push_back(totr(pap[ok[i][j]]));
			}
		}
	}
	sort(p.begin(),p.end(),cmp);
	int ans=toint(p[0]);
	for(int i=1;i<=m-1;i++){
		ans&=toint(p[i]);
	}
	cout<<ans<<endl;
} 
