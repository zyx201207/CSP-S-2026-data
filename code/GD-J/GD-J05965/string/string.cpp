#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,len;
char b[200005],S[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(long long j=0;j<a[i];j++){
			S[len+j]=b[i];
		}
		len+=a[i];
	}
	for(long long i=0;i<len/2;i++){
		if(S[i]!=S[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
