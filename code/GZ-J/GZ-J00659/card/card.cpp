//GZ-J00659 »ÆºÆª 
#include<bits/stdc++.h>
using namespace std;
int a[500010];
vector<int>mp[300010];
vector<pair<int,int> > qu;
bool cmp(pair<int,int> a,pair<int,int>b){
	return a.first<b.first;
}
int ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];mp[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<mp[i].size();j++){
			qu.push_back({mp[i][j-1],mp[i][mp[i].size()-1]});
		}
	}
	sort(qu.begin(),qu.end(),cmp);
	//for(int i=0;i<qu.size();i++){cout<<qu[i].first<<" "<<qu[i].second<<endl;}
	
	for(int i=0;i<n;i++){
		int l=i,r=0;int st=i;
		for(int j=0;j<qu.size();j++){
			
			if(qu[j].first<r&&qu[j].first>l||qu[j].first<i){continue;}
			//cout<<i<<" "<<j<<" "; 
			for(int k=st;k<=qu[j].first;k++){
				ans[a[k]]++;
			}
			st=qu[j].second+1;
			l=qu[j].first;r=qu[j].second;
			//for(int i=1;i<=m;i++){cout<<ans[i]<<" ";}
			//cout<<endl; 
		}for(int k=st;k<n;k++){
			ans[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++){cout<<ans[i]<<" ";}
	return 0;
}

