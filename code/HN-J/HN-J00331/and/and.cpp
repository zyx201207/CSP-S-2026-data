#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],t[200005],tmp[200005];
bool b[200005];
vector<int> now;
vector<int> e[40];
void lisanhua(){
	int now=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])tmp[++now]=a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(tmp+1,tmp+now+1,a[i])-tmp;
	}
}
signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	lisanhua();
	int mx=-1;
	for(int i=1;i<=n;i++){
		int lg=0;
		while((1<<lg)<tmp[a[i]]){
//		cout<<1;
			if(tmp[a[i]]&(1<<lg)&&(e[lg].empty()||e[lg][e[lg].size()-1]!=a[i])){
				e[lg].push_back(a[i]);
			}
			lg++;
		}
		mx=max(mx,lg);
	}
//	for(int i=0;i<=mx;i++){
//		for(int j:e[i])cout<<j<<' ';
//		cout<<'\n';
//	}
	int ma=-1;
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=mx;j>=0;j--){
			int l=lower_bound(e[j].begin(),e[j].end(),a[i])-e[j].begin();
			if(e[j].size()-l<m)continue;//cout<<now.size();
			if(flag){
				int cnt=0;
				for(int k=0;k<e[j].size();k++){
					if(b[e[j][k]])cnt++;
				}
				if(cnt<m)continue;
			}
			if(!flag){
				for(int i=0;i<e[j].size();i++){
					now.push_back(e[j][i]);
					b[e[j][i]]=1;
				}
				flag=1;
			}
			
			for(int i=0;i<now.size();i++){
				if(e[j][lower_bound(e[j].begin(),e[j].end(),now[i])-e[j].begin()]!=now[i]){
					cout<<now[i]<<'\n';
					now.erase(now.begin()+i);
					cout<<now[i]<<'\n';
					b[e[j][i]]=0;
				}
			}
			
		}
		
		int ans=tmp[a[i]];
		if(now.size()<m)ans=0;
		for(int i=0;i<now.size();i++){
			
			ans=ans&tmp[now[i]];
			b[now[i]]=0;
			now.erase(now.begin()+i);
			
		}
		ma=max(ma,ans);
//		cout<<'\n'<<ma<<'\n';
//		if(ans>a[i-1])break;
	}
	cout<<ma;
}
/*
4 1
15 4 3 8
*/
