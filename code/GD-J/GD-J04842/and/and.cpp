#include<bits/stdc++.h>
using namespace std;
int a[200005];
int cnt[16];
#define fre
bool cmp(int u,int v){//注意这是log(max(u,v))，近似30 
	int cntu=0,cntv=0;
	int stku[64],stkv[64],topu=0,topv=0;
	while(u){
		if(u&2)cntu++;
		stku[topu++]=u&2;
		u/=2;
	}
	while(v){
		if(v&2)cntv++;
		stkv[topv++]=v&2;
		v/=2;
	}
	if(cntu!=cntv)return cntu>cntv;
	if(topu!=topv)return topu>topv;
	for(int i=topu;i>=0;i--){
		if(stku[topu]>stkv[topv])return 1;
		if(stku[topu]<stkv[topv])return 0;
		topu--;topv--;
	} 
	return 0;
}
int main(){
	#ifdef fre
		freopen("and4.in","r",stdin);
		freopen("and.out","w",stdout);
	#endif
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0; 
	}
	if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)maxn=max(maxn,a[i]&a[j]);
		}
		cout<<maxn; 
		return 0;
	}
	if(m==n){
		int k=a[1];
		for(int i=1;i<=n;i++)k&=a[i];
		cout<<k;
		return 0;
	}
	if(a[n]<=4){
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		if(cnt[3]>=m)cout<<3;
		else{
			m-=cnt[3];
			if(cnt[4]>=m)cout<<4;
			else{
				m-=cnt[4];
				if(cnt[2]>=m)cout<<2;
				else{
					m-=cnt[2];
					if(cnt[1]>=m)cout<<1;
					else cout<<0;
				}
			}
		}
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]&(-a[i])){
			cnt++;
		}
	}
	if(!cnt){
		cout<<a[n-m+1];
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	//cout<<endl;
	int k=a[1];
	for(int i=1;i<=m;i++)k&=a[i];
	cout<<k;
}
