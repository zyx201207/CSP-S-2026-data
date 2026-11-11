#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,s[N],w,ans;
vector<int> v[N],l[40],k[40];
bool p[N];
void solve(){
	cin>>n>>m;
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			ma=max(ma,s[i]);
		}
		cout<<ma;
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=n;i>=1;i--){
		while(s[i]>0){
			v[i].insert(v[i].begin(),s[i]%2);
			s[i]/=2;
		}
		l[v[i].size()].push_back(i);
	}
	for(int i=1;i<=30;i++){
		if(l[i].size()>=m){
			w=i;
			break;
		}
	}
	ans+=pow(2,w-1);
	for(int i=0;i<w;i++){
		for(int j=0;j<l[w].size();j++){
			if(v[l[w][j]][i])k[j].push_back(l[w][j]);
		}
	}
	for(int i=0;i<l[w].size();i++){
		p[l[w][i]]=1;
	}
	for(int i=w-1;i>=0;i--){
		if(k[i].size()>=m){
			int h=0;
			for(int j=0;j<k[i].size();j++){
				if(p[k[i][j]])h++;
			}
			if(h>=m){
				ans+=pow(2,i);
				for(int j=l[w].size()-1,lj=k[i].size()-1;j>=0&&lj>=0;j--){
					while(l[w][j]==k[i][lj]){
						j--;
						lj--;
					}
					p[l[w][j]]=0;
				}
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
