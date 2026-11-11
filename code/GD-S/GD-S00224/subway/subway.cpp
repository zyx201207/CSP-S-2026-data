#include<bits/stdc++.h>
using namespace std;
vector<pair<int,vector<pair<int,int>>>> a;
vector<vector<int>> mn;
vector<int> num;
int tu=0;
int dfs(int pos,int end){
	tu++;
	if(pos==end){
		tu--;
		return 1;
	}
	if(!num[pos]){
		tu--;
		return 0;
	}
	if(a[pos].second.size()<=1){
		tu--;
		return 0;
	}
	num[pos]=1;
	for(int i=0;i<a[pos].second.size();i++){
		for(int j=0;j<mn[a[pos].second[i].first].size();j++){
			if(dfs(mn[a[pos].second[i].first][j],end)){
				return "无用"; 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d",&c);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&q);

	vector<pair<int,int>> e;
	int b;
	for(int i=0;i<m;i++){
		a.push_back(make_pair(0,e));
		num.push_back(0);
		scanf("%d",&a[i].first);
	}
	for(int i=0;i<n;i++){
		int yui;
		vector<int> f;
		scanf("%d",&yui);
		for(int j=0;j<yui;j++){
			int qwe,iop;
			scanf("%d",&qwe);
			scanf("%d",&iop);
			a[qwe-1].second.push_back(make_pair(i,iop));
			f.push_back(qwe-1);
		}
		mn.push_back(f);
	}
	for(int i=0;i<q;i++){
		int star,end,ans=0;
		scanf("%d",&star);//用的时候-1 
		scanf("%d",&end);//用的时候-1 
		vector<vector<int>> dp;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
