#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,m;
int a[606060];
int b[6060606];
 
signed main(){
//freopen("card.in","r",stdin);
//freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}int f=0;
 
int w=n;
for(int i=1;i<=n;i++){string s="";
for(int u=n-w+1;u<=n;u++){
f=0;
string c="";
for(int j=1;j<u;j++){
if(f!=1)c+=s[j-1];
if(s[j-1]==a[u])
	f=1;}
	s=c;
 char t=a[u];s+=t;}w--;

	for(int j=0;s[j];j++){
		b[s[j]]++;cout<<n<<" "<<s[j]<<endl;
	}
}
for(int i=1;i<=m;i++){
	cout<<b[i]<<" ";
}
return 0;
} 

