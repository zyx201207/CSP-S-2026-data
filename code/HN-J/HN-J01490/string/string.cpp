#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],t=0,sum=0;
string c,s;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;++i){
		cin>>a[i]>>x;
		c+=x;
		for(long long j=0;j<a[i];++j){
			s+=x;
		}
		t+=a[i];
	}
	if(t%2==0){
		for(long long i=0;i<t/2-1;++i){
			if(s[i]!=s[t-i-1]){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	if(t%2!=0){
		for(long long i=0;i<t/2;++i){
			if(s[i]!=s[t-i-1]){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}

	return 0;
}
