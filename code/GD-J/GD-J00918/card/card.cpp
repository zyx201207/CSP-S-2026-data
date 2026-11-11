#include<bits/stdc++.h>
using namespace std;

int a[1000010];
int vis[500010],res[500010],ant[500010],ent[500010];
int t[500010],t2[500010];

int main(){
	freopen("card3.in","r",stdin);
	freopen("card3.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		t[x]++;
		t2[x]++;
	}
	
	int id=0,cnt=0;
	for(int i=n;i>=1;i--){
		int x=a[i];
		if(vis[x]==0){
			vis[x]=1;
			id++;
			res[id]=x;
			ant[x]=i;
		}
		if(id==m){
			cnt=i;
			break;
		}
	}
	for(int i=cnt+1;i<=n;i++){
		int x=a[i];
		if(i!=ant[x]){
			i++;
			while(i<ant[x]){
				int y=a[i];
				ent[y]=1;
				i++;
			}
		}
	}
	
	for(int i=id-1;i>=1;i--){
		int x=res[i];
		int y=res[i+1];
		t2[x]+=t2[y];
	}

	
	for(int i=1;i<=m;i++){
		if(ent[i]==0){
			cout<<t2[i]<<" ";
		}else{
			cout<<t[i]<<" "; 
		}
	}
	return 0;
}
