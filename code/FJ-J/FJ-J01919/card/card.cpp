#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int game[500010];
int c[500010];
int main() {
	freopen("card.in","r",stdin);freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=0;
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0||game[c[a[j]]]!=a[j]||c[a[j]]>t+1){
				c[a[j]]=t+1;
			}
			else{
				t=c[a[j]]-1;
			}
			t++;
			game[t]=a[j];
		}
		for(int j=1;j<=t;j++){
			b[game[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
}

