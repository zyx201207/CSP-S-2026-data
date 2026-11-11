#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],b[M],z[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=m; i++){
		for(int j=1; j<=N; j++)
			z[j]=0;
		int x=1;
		for(int j=1; j<=n; j++){
			for(int k=1; k<=j; k++){
				if(a[x]==z[k])
					x++;
			}
			z[j]=a[x];
			for(int k=1; k<=j; k++){
				if(a[x]==z[k]){
					for(int y=1; y<=N; y++)
						z[y]=0;
					z[1]=a[x];
					continue;
				}	
			}
			//cout<<" "<<i<<" "<<j<<" "<<z[j]<<'\n';         
		}
		for(int j=1; j<=m; j++)
		{
			for(int y=1; y<=n; y++)
			{
				if(z[y]==j){
					b[j]++; 
					break;
				}
			}
			//cout<<i<<" "<<j<<" "<<b[j]<<'\n';
		}
	}
	for(int i=1; i<=m; i++)
		cout<<b[i]<<" ";
	cout<<'\n';
	return 0;
}
