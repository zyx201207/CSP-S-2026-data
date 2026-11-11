#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[500010],b[300010];
struct ju{
	int num=0;
	int so=0;
}c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(c[a[j]-1].num==0){
				
				c[a[j]-1].num=1;
				if(c[a[j]-1].so==0){
					c[a[j]-1].so=j;
				}else{
					c[a[j]-1].so=min(c[a[j]-1].so,j);
				}
				
			}else{
				for(int v=c[a[j]-1].so;v<j;v++){
					c[a[v]-1].num=0;
					c[a[v]-1].so=0;
				}
				c[a[j]-1].num=1;
			}
		}
		for(int l=0;l<m;l++){
			b[l]+=c[l].num;
			
			c[l].num=0;
			c[l].so=0;
			
		}
		
	}
	for(int l=0;l<m;l++){
		cout<<b[l]<<" ";
	}
	return 0;
}
