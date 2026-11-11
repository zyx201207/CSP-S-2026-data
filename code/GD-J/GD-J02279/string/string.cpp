#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	string te="";
	cin>>n;
	long long w=0;
	for(long long i=1;i<=n;i++){
		long long k;
		char s;
		cin>>k>>s;
		w+=k;
		for(long long j=1;j<=k;j++){
			te+=s;
		}
	}
	te=" "+te;
	if(w%2==0){
		w/=2;
		for(long long i=1;i<=w;i++){
			if(te[i]!=te[i+w]){
				ans++;
			}
		}
	}else{
		w=w/2+1;
		for(int i=1;i<=w-1;i++){
			if(te[i]!=te[i+w]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
