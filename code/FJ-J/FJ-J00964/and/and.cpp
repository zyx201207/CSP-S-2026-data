#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int sum=0;
int a[200055];
int ve[200055][33];
string s[200055];
bool cmp(string p,string q){
	for(int i=sum-1;i<=31;i++){
		if(p[i]!=q[i])return p[i]>q[i];
	}
	return 0;
}
void check(int x,int i){
	int aa=1;
	while(x>0){
		ve[i][aa]=x%2;
		aa++;
		x/=2;
	}
	return;
	
}
void get_100(){
	int ans=0;
	for(int i=1;i<=n;i++){
		check(a[i],i);
	}
	for(int i=1;i<=n;i++){
		s[i]=" ";
		for(int j=31;j>=1;j--){
			if(ve[i][j]==1)s[i]+='1';
			else s[i]+='0';
		}
	}
	for(int j=1;j<=31;j++){
		sum=0;
	for(int i=1;i<=n;i++){
		if(s[i][j]==1)sum++;
	}
	if(sum>=m)break;
}
	sort(s+1,s+n+1,cmp);
	for(int j=1;j<=31;j++){
		int flag=1;
	for(int i=1;i<=m;i++){
		if(s[i][j]=='0'){
		flag=0;
		break;
	}
	
	}
	if(flag==1)ans+=pow(2,31-j);
}
	cout<<ans;
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	get_100(); 
	return 0;
}
