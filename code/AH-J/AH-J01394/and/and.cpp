#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x[200005];
int bin[35];
int ss[200005][35];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i];
	sort(x+1,x+1+n,cmp);
	string s;
	for(int i=1;i<=n;i++){
		s="";
		int X=x[i];
		while(X){
			if(X%2)s+='1';
			else s+='0';
			X/=2;
		}
		for(int j=0;j<31;j++){
			if(s[j]=='1'){
				bin[31-j-1]++;
			}
		}
		for(int j=0;j<31;j++){
			if(s[j]=='1')ss[i][31-j-1]=1;
		}
	}
	int ans,mm=m,mmm=m;
	int xuan[200005]={0},cur=0;
	for(int i=0;i<=31;i++){
		if(bin[i]>=m&&mm>0){
			xuan[++cur]=i;
			mm--;
		}
	}
	for(int i=1;i<=n;i++){
		bool f=1;
		for(int j=1;j<=cur;j++){
			if(ss[i][xuan[j]]!=1){
				f=0;
			}
		}
		if(mmm==m&&f)ans=x[i];
		if(f&&mmm)ans=ans&x[i],mmm--;
	}
	cout<<ans;
	return 0;
} 
