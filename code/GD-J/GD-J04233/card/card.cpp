#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int vis[N];
int first_position[N];
int a[N];
int ans[N];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(vis[a[i]]){
				while(v.size()!=first_position[a[i]]){
					if(vis[v.back()]<=1)vis[v.back()]=0;
					else vis[v.back()]--;
					v.pop_back();
				}
				v.push_back(a[i]);
				first_position[a[i]]=v.size();
			}
			else{
				v.push_back(a[i]);
				first_position[a[i]]=v.size();
				vis[a[i]]++;
			}
		}
		for(int i=0;i<v.size();i++){
			ans[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d",ans[i]);
	fclose(stdin);
	fclose(stdout);
}
