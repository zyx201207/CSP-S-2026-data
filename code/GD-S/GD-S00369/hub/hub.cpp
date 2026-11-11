#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a,b,c[100005],fa[100005],cnt,ans;
int find(int x){
	cnt++;
	if(fa[x]==x)return x;
	else fa[x]=find(fa[x]);
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>a>>b;
	while(b--){
		ans=0;
		int x,y;
		cin>>x>>y;
		for(int i=0;i<x;i++){
			cin>>c[i];
			fa[i]=i;
		}sort(c,c+x);
		for(int i=0;i<x;i++){
			for(int j=i+1;j<x;j++){
				if(c[j]-c[i]<=y){
					int da=find(c[j]),db=find(c[i]);
					if(da!=db){
						fa[da]=db;
					}
				}
			} 
		}for(int i=0;i<x;i++){
			int da=find(x);
			if(cnt>=4){
				ans++; 
			}cnt=0;
		}cout<<ans<<endl;
	}
	return 0;
} 
