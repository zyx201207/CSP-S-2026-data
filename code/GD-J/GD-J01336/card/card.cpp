#include<bits/stdc++.h>
using namespace std;
int n,m,l=1;
int a[500000],b[300000],c[500000];
void dfs(int c[],int a[],int b[],int l){
	for(int i=l;i<=n;i++){
		int s=0;
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i]){
				for(int x=j;x>=j+s;x++){
					a[x]=-1;
					break;
				}
			}
			s++;
		}	
	}
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			f++;
			b[a[i]]++;
		}else{
			a[i]=c[i];
		}
	}
	l++;
	if(l==n) return;
	dfs(c,a,b,l);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(b,0,sizeof(b));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	dfs(c,a,b,l);
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
