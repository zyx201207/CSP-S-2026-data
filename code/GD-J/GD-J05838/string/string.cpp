#include <bits/stdc++.h>
using namespace std;
long long q,n,sum,l;
string s,t,p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		cin>>s;
		l+=n;
		for(int i=1;i<=n;i++){
			t+=s;
		}
	}
	long long len=t.size();
	if(len%2==0){
		len/=2; 
	}else{
		len=len/2+1;
	}
	for(int i=0;i<len;i++){
		if(t[i]!=t[l-i-1]){
			sum++;
		}	
	}
	cout<<sum;
	return 0;
}
