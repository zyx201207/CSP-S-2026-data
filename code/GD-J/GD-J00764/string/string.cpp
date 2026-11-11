#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
string c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		long long a,b;
		string p,q;
		cin>>a>>p;
		cin>>b>>q;
		long long k=min(a,b);
		if(p==q){
			cout<<0;
			return 0;
		}else{
			cout<<k;
			return 0;
		}
	}
		string s;
		for(long long  i=1;i<=n;i++){
			cin>>a[i]>>c[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=a[i];j++){
				s=s+c[i];
			}
		}
		long long cnt=0;
		for(long long i=1;i<=s.size()/2;i++){
			if(s[i-1]==s[s.size()-i]){
				cnt++;
			}	
		}
		cout<<(s.size()/2)-cnt;
	return 0;
}
