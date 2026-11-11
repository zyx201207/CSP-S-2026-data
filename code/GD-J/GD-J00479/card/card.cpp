#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N];
int stk[N],tot,inq[N];
int ans[N];
bool isA=1;
int lst[N],cntB,aa[N],ctt; 
void svA(){
	for(int i=2;i<=n+1;i++){
		if(a[i]!=a[i-1]) lst[a[i-1]]=i-1; 
	} 
	for(int i=1;i<=m;i++){
		cout<<lst[i]<<" ";	
	}
} 
void svB(){
	for(int i=2;i<=n;i+=2){
		if(a[i]==a[i-1]) aa[++ctt]=a[i];
		else aa[++ctt]=a[i-1],aa[++ctt]=a[i];  
	}
	if(n&1&&a[n]!=a[n-1]) aa[++ctt]=a[n];
	for(int ron=1;ron<=ctt;ron++){
		for(int i=ron;i<=ctt;i++){  
			if(inq[aa[i]]){
				while(tot&&stk[tot]!=aa[i]) inq[stk[tot]]=0,tot--;
			}
			else stk[++tot]=aa[i],inq[aa[i]]=1;
		}
		while(tot) inq[stk[tot]]=0,ans[stk[tot]]++,tot--;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m) cout<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]) isA=0;
		if(i>1&&a[i]!=a[i-1]) cntB++;
	}
	if(isA) { svA(); return 0; }  
	for(int ron=1;ron<=n;ron++){
		for(int i=ron;i<=n;i++){  
			if(inq[a[i]]){
				while(tot&&stk[tot]!=a[i]) inq[stk[tot]]=0,tot--;
			}
			else stk[++tot]=a[i],inq[a[i]]=1;
		}
		while(tot) inq[stk[tot]]=0,ans[stk[tot]]++,tot--;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m) cout<<" ";
	}
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
