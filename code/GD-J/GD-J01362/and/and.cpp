#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e5+10;
int n,m,ans;
int a[N],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=29;i>=0;i--){
		int cnt=0;
		vector<int> vis1;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(((a[j]>>i)&1)==0){
				vis1.push_back(j);
			}
			else{
				cnt++;
			} 
		}
		if(cnt>=m){
			ans+=1<<i;
			for(int j=0;j<vis1.size();j++){
				vis[vis1[j]]=1;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
/*
4 2
3 15 12 12
*/
