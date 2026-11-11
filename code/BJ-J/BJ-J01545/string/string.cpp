#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200001];
	char c[200001];
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string b1="",b2="";
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			b1+=c[i];
		}
	}
	
	long long l=0;
	for(long long i=1;i<=n;i++){
		l+=a[i];
	}
	
	for(long long i=l-1;i>=0;i--){
		b2+=b1[i];
	}
	
	if(b1==b2){
		cout<<0;
	}else{
		long long cnt=0;
		if(l%2==0) l=l/2-1;
		else l=l/2;
		for(long long i=0;i<=l;i++){
			if(b1[i]!=b2[i]) cnt++;
		}
		
		cout<<cnt;
	}
	
	return 0;
}


