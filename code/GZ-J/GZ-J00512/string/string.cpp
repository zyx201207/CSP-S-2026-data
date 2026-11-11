//GZ-J00512 易煊培 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

long long n,k=0,h=0,r=0,x;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		long long x;
		string c;
		cin>>x>>c;
		r+=x;
		while(x--) {
			s=s+c;
		}
	}
	r-=1;
	while(h<=r){
		if(s[h]!=s[r]) k++;
		h++;
		r--;
	}
	cout<<k;
	return 0;
}  
