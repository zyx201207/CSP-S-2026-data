#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],b[500005],g=0;
queue<int>q1;
void find(int x){
	for(int i=1;i<=g;i++){
		if(x==b[i]){
			for(int j=i;j<=n;j++)
			g=i-1;
			return;
		} 
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		scanf("%d",&a[i]);
		q1.push(a[i]);
	}	
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		g=0;
		for(int j=1;j<=i-1;j++) q1.pop();
		for(int j=i;j<=n;j++){
			int x=q1.front();
			find(x);
			g++;
			b[g]=x;
			q1.pop();
		}
		for(int j=1;j<=g;j++) sum[b[j]]++;
		for(int i=1;i<=n;i++) q1.push(a[i]);
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
}
