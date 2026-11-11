#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=1e7;
long long a[N],ans=0,b[N],mx;
int n;
char c[N];
string s1;
char c1;
bool is(string s){
	long long m=s.length();
	if(m%2==0){
		for(long long i=0;i<=m/2-1;i++){
			if(s[i]!=s[m-i-1]) return 0;
		}
	}
	else{
		for(long long i=0;i<m/2-1;i++){
			if(s[i]!=s[m-i-1]) return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[c[i]-'0']++;
		if(a[i]!=a[i+1]) f=0;
		for(int j=1;j<=a[i];j++){
			s1=s1+c[i];
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(mx<b[c[i]-'0']){
				mx=b[c[i]-'0'];
				c1=c[i];
			}
		}
		mx=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=c1) mx++;
		}
		cout<<mx*a[1];
	}
	if(is(s1)) cout<<0;
	else{
		long long p=s1.length();
		for(long long i=0;i<=p/2-1;i++){
			if(s1[i]!=s1[p-1-i]) ans++;
		}
		cout<<ans;
	}
	return 0;
} 
