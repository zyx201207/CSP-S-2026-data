#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[200005];
	long long n,a,sum,dc,m;
	char c;
	cin>>n;
	dc=0;
	sum=0;
	for(long long i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(long long j=1;j<=a;j++){
			s[sum+1]=c;
			sum=sum+1;
		}
	}
	m=sum/2;
	for(long long i=0;i<m;i++){
			if(s[i+1]!=s[sum-1]){
					dc++;
				}
		}
	cout<<dc;
}
