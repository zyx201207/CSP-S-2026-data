#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	long long n,a;
	char c;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long b=s.size();
	long long d=b/2;
	long long q=0;
	for(long long k=0;k<d-1;k++){
		for(long long f=b-1;f>d;f--){
			if(s[k]!=s[f]){
				q++;
			}
		}
	}
	cout<<q;
	return 0;
}
