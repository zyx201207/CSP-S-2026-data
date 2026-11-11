#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],ans[500005];
vector<int> q[500005];
bool find(int x,int y){
	bool flag=false;
	for(int i=0;i<q[x].size();i++){
		if(q[x][i]==y){
			flag=true;
			break;
		}
	}
	return flag;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		vector<int> v;
    		if(!q[i].empty()&&find(i,a[j])){
    			for(int k=0;k<q[i].size();k++){
    				if(q[i][k]==a[j]) break;
    				v.push_back(q[i][k]);
				}
				q[i]=v;
				q[i].push_back(a[j]);
			}
			else{
				q[i].push_back(a[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(find(j,i)) ans[i]++;
		}
		cout<<ans[i]<<" ";
	}
	return 0;
} 
