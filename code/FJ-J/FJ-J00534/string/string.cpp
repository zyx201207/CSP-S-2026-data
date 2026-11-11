#include<bits/stdc++.h>
using namespace std;
long long l,o=1,n,sum,k,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			o=0;
		}
	}
	if(o==1){
		for(long long i=1;i<=n;i++){
			s[i]=c[i];
		}
		for(long long i=1;i<=n/2;i++){
			if(s[i]!=s[n-i+1]){
				sum++;
			}
		}
		cout<<sum*a[1];
	}else{
		for(long long i=1;i<=n;i++){
			l+=a[i];
			for(long long j=1;j<=a[i];j++){
				s[k]=c[i];
				k++;
			}
		}
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				sum++;
			}
		}
		cout<<sum;
	}
	
	return 0;
}
