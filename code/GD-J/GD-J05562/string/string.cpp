#include<bits/stdc++.h>
using namespace std;
long long n,x,k=0,sum=0;
string s="";
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long i=1;i<=n;i++){
		cin>>x>>a;
		for(long long j=1;j<=x;j++){
			s+=a;
		}
	}
	for(long long i=s.size()-1;i>=s.size()-s.size()/2;i--){
		if(s[k]!=s[i]) sum++;
		k++;
	}
	cout<<sum;
	return 0;
} 
