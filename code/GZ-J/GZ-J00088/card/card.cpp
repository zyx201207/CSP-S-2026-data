//GZ-J00088 遵义市新蒲新区天立学校 袁铭骏侨 
#include<bits/stdc++.h>
using namespace std;
struct pai{
	int dian;
	int next;
	bool fu;
}p[300005];
int ans[500005];
int n,m; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].dian;
		for(int j=i-1;j>=1;j--){
			if(p[i].dian==p[j].dian){
				p[i].next=j;
			}
		}	
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			p[j].fu=0;
		}
		for(int j=i+1;j<=n;j++){
			if(p[j].next>i){
				for(int l=p[j].next;l<j;l++){
					p[l].fu=1;
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			if(p[j].fu==0){
				ans[p[j].dian]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
