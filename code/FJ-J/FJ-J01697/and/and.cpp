#include<bits/stdc++.h>//65pts  哈哈哈哈 
#define int long long
using namespace std;
int n,m,a[200005],fs[4],dfm,f[21]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};
bool isf=1,fla=1,flb=1;
void dfs(int x,int y,int z){//选了几个  分数  最后 
	if(x==m){
		dfm=max(dfm,y);
		return;
	}
	for(int i=z+1;i<=n-m+x+1;i++){
		if(x==0)dfs(x+1,a[i],i);
		else dfs(x+1,y&a[i],i);
	}
}
bool isa(int x){
	for(int i=0;i<=20;i++){
		if(x==a[i])return 1;
	}
	return 0;
}
int lb(int x){
	return x&-x;
}
signed main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	if(m==1){
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			dfm=max(x,dfm);
		}
		cout<<dfm;
		return 0;
	}
	
	if(m==n){
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(i==1)dfm=x;
			else dfm=(dfm&x);
		}
		cout<<dfm;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)isf=0;
		if(fla){
			if(isa(a[i])==0)fla=0;
		}
		if(a[i]!=i-1)flb=0;
	}
	
	if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				dfm=max(dfm,(a[i]&a[j]));
			}
		}
		cout<<dfm;
	}
	
	if(n<=20){
		dfs(0,0,0);
		cout<<dfm;
		return 0;
	}
	
	if(isf){
		for(int i=1;i<=n;i++){
			fs[a[i]]++;
		} 
		if(fs[3]>=m)cout<<3;
		else if(fs[3]+fs[2]>=m)cout<<2;
		else if(fs[3]+fs[1]>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	
	if(fla){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	
	if(flb){
		dfm=n-1;
		int x=1;
		for(int i=2;i<=m;i++){
			if(i==x+1){
				dfm-=lb(dfm);
				x*=2;
			}
		}
		cout<<dfm;
		return 0;
	}
	cout<<0;
	return 0;
}
