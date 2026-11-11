#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],cnt,ccnt[N],ans[N],vis[N],dp[N],ts1=1;
char a2[N][32];
void totwo(int x){
	cnt++;
	ccnt[cnt]=0;
	for(int i=1;i<=31;i++){
		a2[cnt][i]='0';
	}
	while(x>0){
		++ccnt[cnt];
		a2[cnt][30-ccnt[cnt]+1]=x%2+'0';
		x/=2;
	}
}
int toten(string s){
	int bs=1;
	int sm=0;
	for(int i=30;i>=1;i--){
		sm+=bs*(s[i]+0);
		bs*=2;
	}
	return sm;
}
int num(string s,int nw){
			for(int j=1;j<=30;j++){
				s[j]=(s[j]-'0')&(a2[nw][j]-'0');
			}
	return toten(s);
}

string ch(string s,int nw){
			for(int j=1;j<=30;j++){
				s[j]=(s[j]-'0')&(a2[nw][j]-'0');
			}
	return s;
} 
int dfs(int nw,int nwm,int ans,string s){
	if(nw>n)return 0;
	if(nwm==m)return ans;
	return max(dfs(nw+1,nwm+1,ans=num(s,nw),ch(s,nw)),dfs(nw+1,nwm,ans,s));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		totwo(a[i]);
	}
	if(m==n){
		string s="1111111111111111111111111111111";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=30;j++){
				s[j]=(s[j]-'0')&(a2[i][j]-'0');
			}
		}
		cout<<toten(s);
	}
	else if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(n<=20){
		cout<<dfs(1,0,0,"1111111111111111111111111111111");
	} 
	else{
		int mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}

	return 0;
} 
