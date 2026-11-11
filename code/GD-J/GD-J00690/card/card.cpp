#include<bits/stdc++.h>
using namespace std;
struct node{
	char m,n;
	long long a,b,c;
};
long long adj[1000000];
node adv[100000];
long long x[10000000][3],y[100000],z[100000];
bool cpu(long long x,long long y){
	return x>y;
}
int main(){
	long long a,b,c,i,j,m,n,k;
	char t;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(i=0;i<a;i++){
		cin>>adj[i];
		y[adj[i]]++;
		if(y[adj[i]]==1){
		z[adj[i]]=i;	
		}
		//x[adj[i]][0]=1;
	} 
	for(i=0;i<a;i++){
		for(j=i;j<a;j++){
			if(x[adj[j]][1]==0){
				x[adj[j]][0]++;
				x[adj[j]][1]=1;
			}	
			else{
				m=j-1;
				while(adj[m]!=adj[j]){
					if(x[adj[j]][2]==0){
						x[adj[j]][0]--;
						x[adj[j]][2]=1;
					}
					
				//	cout<<adj[m]<<" "<<m<<" "<<x[adj[m]][0]<<" ";
					m--;
				}
			//	cout<<endl;
				
			}
		}
		for(j=i;j<a;j++){
			x[adj[j]][1]=0;
			x[adj[j]][2]=0;
		}
	}
	for(i=1;i<=b;i++){
		cout<<x[i][0]<<" ";
	}
	return 0;
} 
