#include<bits/stdc++.h> 
using namespace std;
int ans[300050];
int nownum=0;
int now[300050];
int pai[500050];
int cx[300050][2];
main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	int i=1;
	while(i<=n){
		cin>>pai[i];
	i++;}
	
	i=1;
	while(i<=n){
		int j=1;
		while(j<=n){
			cx[j][1]=0;
			cx[j][0]=0;
		j++;}
		nownum=0;
		j=i;
		while(j<=n){
			nownum++;
			now[nownum]=pai[j];
			if(cx[pai[j]][0]==1){
				int q=cx[pai[j]][1];
				int lsls=q;
				while(q<=nownum){
					cx[q][0]=0;
					cx[q][1]=0;
					now[q]=0;
				q++;}
				nownum=lsls;
				now[nownum]=pai[j];
			}else{
				cx[pai[j]][0]=1;
				cx[pai[j]][1]=nownum;
			}
		j++;}
		j=1;
		while(j<=nownum){
			ans[now[j]]++;
		j++;}
		
	i++;}
	
	i=1;
	while(i<=m){
		cout<<ans[i]<<" ";
	i++;}
	
	
	return 0;
}
