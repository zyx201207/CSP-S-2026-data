#include <bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int a,int b){
	if(b==0){
	return a;
	}
	else{
	return gcd(b,a%b);
	}
}
ll s[200001],mod=1,f[2001][2001],x[200001];
ll n,u=0,cnt=0;
char a[20001],c='+',b[200001];
string ss;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	memset(x,0,sizeof(x));
	memset(f,0,sizeof(f));
	for(ll i=1;i<=n;i++){
		int k=i-1,w;
		string l;
		cin>>w;
		cin>>l;
		b[k]=l[0];
		x[i]=w;
		if(b[k]!=c){
		++cnt;
		}
		s[cnt]+=x[i];
		a[cnt]=b[k];
		c=b[k];
	}
	if(cnt==1){
		cout<<"0"<<endl;
		return 0;
	}
	if(cnt==2){
		cout<<min(s[1],s[2]);
		return 0;
	}
	mod=gcd(max(s[1],s[2]),min(s[1],s[2]));
	for(ll i=3;i<=cnt;i++){
	mod=gcd(max(mod,s[i]),min(mod,s[i]));
	}
	for(ll i=1;i<=cnt;i++){
	for(ll j=1;j<=s[i]/mod;i++){
	ss+=a[i-1];
	}
	u+=s[i]/mod;
	}
	for(ll i=1;i<=u;i++){
		f[i][i]=0;
	}
	for(ll i=0;i<=u-2;i++){
		if(ss[i]==ss[i+1]){
		f[i+1][i+2]=0;
		}
		else{
		f[i+1][i+2]=1;
		}
	}
	for(ll len=3;len<=u;len++){
		for(ll i=1;i+len-1<=u;i++){
			int j=i+len-1;
			if(ss[i-1]==ss[j-1]){
				f[i][j]=f[i+1][j-1];
			}
			else{
				f[i][j]=f[i+1][j-1]+1;
			}
		}
	}
	cout<<f[1][u]*mod;
	return 0;
}

