#include<bits/stdc++.h>
using namespace std;
long long n,a,l=0,r,sum=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a);
		cin>>c;
		for(long long j=1;j<=a;j++){
			s=s+c;
		}
	}
	r=l=s.size();
	if(l%2==0){
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[r-1]){
				sum++;
			}
			r=r-1;
		}
	}else{
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[r-1]){
				sum++;
			}
			r=r-1;
		}
	}
	cout<<sum;
	return 0;
}  
