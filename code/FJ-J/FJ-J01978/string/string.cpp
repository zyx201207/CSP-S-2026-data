#include <bits/stdc++.h>
using namespace std;
long long n,sum=0,lian=0;
string c;
bool hui(string a){
	string b;
	int l=a.length();
	for (int i=l-1;i>=0;i--){
		b=b+a[i];
	}
	if (b==a) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		long long num;
		string s;
		cin>>num>>s;
		sum+=num;
		for (long long j=lian+1;j<=lian+num;j++){
			c=c+s;
		}
		lian=lian+num;
	}
	if (hui(c)==1){
		cout<<0;
		return 0;
	}
	int l=c.length();
	long long cnt=0;
	string x,y;
	if (l%2==1){
		for (long long i=0;i<(l-1)/2;i++){
			x=x+c[i];
		}
		for (long long i=l-1;i>=(l+1)/2;i--){
			y=y+c[i];
		}
		for (long long i=0;i<(l-1)/2;i++){
			if (x[i]!=y[i]) cnt++;
		}
		cout<<cnt;
	}else{
		for (long long i=0;i<l/2;i++){
			x=x+c[i];
		}
		for (long long i=l-1;i>=l/2;i--){
			y=y+c[i];
		}
		for (long long i=0;i<l/2;i++){
			if (x[i]!=y[i]) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
