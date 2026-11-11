#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],b[N];
int c[N],d[N];
int n,m,t=0;
bool solve(int u){
	int flag=1,cnt;
	for(int i=1;i<=t;i++){
		if(c[i]==u)cnt=i,flag=0;
	}
	if(flag){
		c[t+1]=u;
		t++;
	}else{
		for(int i=cnt+1;i<=n;i++){
			c[i]=0;
			d[c[i]]=1;
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(500>=n){
		for(int l=1;l<=n;l++){
			for(int i=1;i<=m;i++){
				d[i]=0;
				c[i]=0;
			}
			t=0;
			for(int i=l;i<=n;i++){
				if(d[a[i]]==0){
					solve(a[i]);
				}
			}
			for(int i=1;i<=n;i++){
				b[c[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" "; 
		}
	}
	return 0; 
}

