#include <bits/stdc++.h>
using namespace std;
int n;
long long zw,cnt,d,cnt2;
int a[200000];
char c[200000];
string b;
string w;
string y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	 cin>>n;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 	cin>>c[i];
	 	d+=a[i];
	 	for(int j=1;j<=a[i];j++){
	 		b+=c[i];
		 }
	 }
	if(d%2!=0) zw=(d+1)/2;
	 else zw=d/2-1;
	for(int i=0;i<zw;i++){
		w+=b[i];
	}
	for(int i=zw;i<b.size();i++){
		y+=b[i];
	}
	for(int i=0;i<zw;i++){
		if(w[i]!=y[i]) cnt++;
	}
	for(int i=0;i<zw;i++){
		if(w[i]!=y[i]) cnt++;
	}
	if(w.size()>y.size()) cnt=y.size();
	else cnt=w.size();
	 cout<<cnt;
	return 0;
} 
//aabbc
