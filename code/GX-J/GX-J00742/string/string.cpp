#include<bits/stdc++.h>
using namespace std;
    long long num;
    char a;
    string s;
    int n;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);	
    cin>>n;
   long long len=0;
   long long m=0;
    while(n--){
		cin>>num>>a;
		len+=num;
		for(long long i=m;i<m+num;i++) {
			s[i]=a;
		}
	m+=num;
	}
	
	if(len%2==0){
		string l,r;
		long long k=0;
		long long ans=0;
		for(long long i=0;i<len/2;i++){
			l[i]=s[i];
		}
		for(long long i=len/2;i<len;i++){
			r[k]=s[i];
			k++;
		}
			string s1;
	         long long k1=0;
	for(long long j=k-1;j>=0;j--){
		s1[k1]=r[j];
		k1++;
	}
	for(long long i=0;i<len/2;i++){
		if(l[i]!=s1[i]){
			s1[i]=l[i];
			ans++;
			}
	}
	cout<<ans;
	}
	
	else {
		string l,r;
		long long k=0;
		long long ans=0;
		for(long long i=0;i<len/2;i++){
			l[i]=s[i];
		}
		for(long long i=len/2+1;i<len;i++){
			r[k]=s[i];
			k++;
		}
			string s1;
	         long long k1=0;
	for(long long j=k-1;j>=0;j--){
		s1[k1]=r[j];
		k1++;
	}
	for(long long i=0;i<len/2;i++){
		if(l[i]!=s1[i]){
			s1[i]=l[i];
			ans++;
			}
	}
	cout<<ans;
	}
    return 0;
	}
