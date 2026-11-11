#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
string s[maxn];
string f(long long x){
	string L,L2;
	while(x){
		L+=x%2+'0';
		x/=2;
	}
	int t=L.size();
	for(int i=0;i<t;i++)
		L2[t-i-1]=L[i];
	return L2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,iMAX=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		iMAX=max(iMAX,a);
	}
	cout<<iMAX;
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m;
long long a[maxn];
string s[maxn];
string dp[maxn][maxn];
string f(long long x){
	string L,L2;
	while(x){
		L+=x%2+'0';
		x/=2;
	}
	int t=L.size();
	for(int i=0;i<t;i++)
		L2[t-i-1]=L[i];
	return L2;
}
string f2(string u,string v){
	string andi;
	for(int i=0;i<min(u.size(),v.size());i++) andi[i]=(u[i]-'0'&v[i]-'0')+'0';
	return andi;
}
string cmp(string u,string v){
	if(u>v) return u;
	return v;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=f(a[i]);
		cout<<s[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			dp[i][j]=cmp(dp[i-1][j],f2(dp[i-1][j-1],s[i]));
		}
	
	cout<<dp[n][m];
	cout<<s[1];
	return 0;
}*/
