#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
vector<vector<int>>v;
map<int,int>cnt;
//void print(int k){
//	for(int i=0;i<v[k].size();i++){
//		cout<<v[k][i];
//	}
//	cout<<endl;
//}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int youxi=0;
	for(int i=0;i<n;i++){
		map<int,bool>mf;
		map<int,int>mw;
		v.push_back({});
		for(int k=1+i;k<=n;k++){
			if(!mf[a[k]]){
				v[i].push_back(a[k]);
				mf[a[k]]=true;
				mw[a[k]]=k;
			}else{
				int len=v[i].size(),shan=len-mw[a[k]],t=mw[a[k]],t2=t;
				for(int j=mw[a[k]]+1;j<len;j++){
					mf[v[i][mw[a[k]]+1]]=false;
					print(i);
					v[i].erase(v[i].begin()+mw[a[i]]);
				}
				youxi++;
				break;
			}
		}
	}
	int len1=v.size();
	for(int i=0;i<len1;i++){
		int len2=v[i].size();
		for(int j=0;j<len2;j++){
			cnt[v[i][j]]++;
		}
	}
	bool b=false;
	for(int i=1;i<=m;i++){
		if(b)cout<<' ';
		cout<<cnt[i];
		b=true;
	}
	return 0;
}