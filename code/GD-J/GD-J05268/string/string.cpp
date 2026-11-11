#include<bits/stdc++.h>
using namespace std;
string S[100000+10];
long long s[100000+10];
string a[10000000+10];
long long sum,ans;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	long long n;
	cin>>n;long long sum=0;
	
	for(long long i=1;i<=n;i++){
		cin>>s[i]>>S[i];
		
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=s[i];j++){
			a[j]=S[i];
			sum++;
		}
	}
	long long r=1,l=sum;
	while(r<=l){
		
		long long mid=(r+l)/2+1;
		if(a[r]!=a[l])
			ans++;
			r++;
			l--;
			if(r>mid)
			break;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
