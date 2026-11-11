#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],sum=0;
char c[200002];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(a[1]<=100000){
		for(int i=1;i<=n;i++){
			for(long long j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		for(long long i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				sum++;
			}
		}
		cout<<sum;
	}else{
		for(int i=1;i<=n/2;i++){
			sum+=a[i];
		}
		cout<<sum;
	}
	return 0;
}
