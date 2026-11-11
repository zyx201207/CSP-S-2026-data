#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int cnt;
int tong[100010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> path;
		for(int j=i;j<=n;j++){
			bool flag=1;
			int biao;
			for(int k=0;k<path.size();k++){
				if(path[k]==a[j]){
					flag=0;
					biao=k;
					break;
				}
			}
			if(flag){
				path.push_back(a[j]);
				continue;
			}else{
				for(int k=biao;k<path.size();k++){
					path.pop_back();
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<path.size();k++){
				if(j==path[k]){
					tong[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<tong[i]<<' ';
	return 0;
}
