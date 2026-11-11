#include<bits/stdc++.h>
using namespace std;
long long n,a[114514],wei,wei2;
char c[114514];
string s,s2;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		wei+=a[i];
	}
	wei2=wei;
	wei/=2;
	long long t=1,j=0;
	for(long long i=1;i<=wei;i++){
		j++;
		s+=c[t];
		if(j==a[t]){j=0;t++;}
	}
//	cout<<t<<'\n';
	j=(wei2%2);
	if(j==a[t]){j=0;t++;}
	for(int i=wei+(wei2%2)+1;i<=wei2;i++){
		j++;
		s2+=c[t];
		if(j==a[t]){j=0;t++;}
	}
	for(int i=0;i<wei;i++){
		if(s[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
