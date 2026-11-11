#include<bits/stdc++.h>
using namespace std;
int const N=1e6+1,M=3e6+1;
int cnt[M];
struct o{
	int p;
	int in;
	int l=1;
}a[N];
int main(){
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[n+1][m+1];
	memset(c,0,sizeof(c));


	int sum=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].p;
		c[a[i].p][c[a[i].p][0]+1]=i;
		a[i].in=c[a[i].p][c[a[i].p][0]];
		c[a[i].p][0]++;
		if(c[a[i].p][0]!=1 and a[c[a[i].p][c[a[i].p][0]--]].l==1){
			for(int j=c[a[i].p][0]-1;j<=c[a[i].p][0];j++){
				a[j].l=0;
			}
		}
		
		
 }
	for(int i=1;i<=n;i++){
			if(a[i].l==1) cnt[a[i].p]++;
	}
	for(int k=2;k<=n;k++){
				for(int i=k;i<=n;i++){
			if(c[a[i].p][0]!=1 and a[c[a[i].p][0]--].l==1 and c[a[i].p][c[a[i].p][0]--]>=k){
			for(int j=c[a[i].p][0]-1;j<=c[a[i].p][0];j++){
				a[j].l=0;
			}
		}
		
		
 			}
 			for(int i=1;i<=n;i++){
			if(a[i].l==1) cnt[a[i].p]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
