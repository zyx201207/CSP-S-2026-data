#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,sum=0;
    char c;
    string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long len=s.size();
	for(long long i=0,j=len-1;i<=len/2-1,j>=(len+1)/2;i++,j--){
		if(s[i]!=s[j]) sum++;
	}
	cout<<sum;
	return 0;
} 
