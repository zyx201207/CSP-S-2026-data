#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],ans[m+5]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		vector<int> now;
		for(int j=i;j<n;j++){
			int g=-1;
			for(int k=0;k<now.size();k++){
				if(now[k]==a[j]){
					g=k;
					break;
				}
			}
			if(g==-1) now.push_back(a[j]);
			else{
				for(auto it=now.begin()+g;it!=now.end();it++) now.erase(it);
				now.push_back(a[j]);
			}
		}
		for(int i=0;i<now.size();i++){
			ans[now[i]-1]++;
		}
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
	
	return 0;
} 

