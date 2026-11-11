#include<bits/stdc++.h>
using namespace std;
int z[100005];
struct node{
	int x;
	int y;
};
node a[100005];
int c[100005];
int v[100005];

int main(){
	

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		
	} 
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			v[a[j].x]++;
			
			if(v[a[j].x]>1){
				for(int o=a[j].y;o<=j;o++){
					z[o]++;
				}
			}else{
				a[j].y=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(z[j]<1){ c[a[j].x]++; }
			
			v[j]=0;
			z[j]=0;
			a[j].y=0;
		}
		cout<<endl;
}
	for(int j=1;j<=m;j++){
		cout<<c[j]; 
		
}
} 
//4 3
//1 2 1 3
