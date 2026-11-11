#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
int a[maxn],b[maxn];
int c[maxm];
bool d[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(d,0,sizeof d);
		int x=0;
		for(int j=i;j<=n;j++){
			bool st=0;
			for(int k=1;k<=x;k++){
				if(a[j]==b[k]&&!st) st=1,x=k-1;
				if(st) b[k]=0;
			}
			b[x+1]=a[j],x++;
		}
		for(int j=1;j<=x;j++){
			d[b[j]]=1;	
		}
		for(int j=1;j<=m;j++) 
			if(d[j]) c[j]++;
		//cout<<endl;
	}
	for(int j=1;j<=m;j++) 
		cout<<c[j]<<' ';
	return 0;
}
