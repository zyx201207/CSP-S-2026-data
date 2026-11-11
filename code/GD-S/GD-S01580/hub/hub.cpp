#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=205;
const int inf=1e9;
char c[N];
int check(char x){
	if(x=='+'||x=='-') return 1;
	else if(x=='*'||x=='/') return 2;
	else if(x=='^') return 3;
	else return 0;
}
int n,num,cnt,idx,cntp,idxp,cntpp,idxpp;
int st[N],stp[N],stpp[N];
char st1[N],st1p[N],st1pp[N];
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	
	cin>>c+1;
	n=strlen(c+1);
	for(int i=1;i<=n;i++){
		if(!check(c[i])) num=num*10+c[i]-'0';
		else {
			st[++idx]=num;
			num=0;
			st1[++cnt]=c[i];
		}
	}
	st[++idx]=num;
	
	for(int i=1;i<=cnt;i++){
		if(check(st1[i])==3&&st[i]!=inf) st[i+1]=pow(st[i],st[i+1]),st[i]=inf,st1[i]='%';
	}
	for(int i=1;i<=idx;i++) if(st[i]!=inf) stp[++idxp]=st[i];
	for(int i=1;i<=cnt;i++) if(st1[i]!='%') st1p[++cntp]=st1[i];
	
	
	for(int i=1;i<=cntp;i++){
		if(check(st1p[i])==2&&stp[i]!=inf){
			if(st1p[i]=='*') stp[i+1]=stp[i]*stp[i+1],stp[i]=inf,st1p[i]='%';
			else stp[i+1]=stp[i]/stp[i+1],stp[i]=inf,st1p[i]='%';
		}
	}
	for(int i=1;i<=cntp;i++) if(st1p[i]!='%') st1pp[++cntpp]=st1p[i];
	for(int i=1;i<=idxp;i++) if(stp[i]!=inf) stpp[++idxpp]=stp[i];
	
	int ans=stpp[1];
	for(int i=2;i<=idxpp;i++) {
		if(st1pp[i-1]=='+') ans+=stpp[i];
		else ans-=stpp[i];
	}
	cout<<ans;
	
	return 0;
}  
