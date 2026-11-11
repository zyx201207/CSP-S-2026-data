#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,p=0,q=0;
	string m;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long k;
		string s;
		cin>>k>>s;
//		p+=k;
		for(int j=1;j<=k;j++)m=m+s;
	}
	p=m.size();
	for(int i=0;i<(p+1)/2;i++){
		if(m[i]!=m[p-1-i]){
			q++;
//			cout<<i<<' '<<p-i;
		}
	}
	cout<<q;
	return 0;
}

