#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,c,y;
char z;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>k>>z;
		for(int i=0;i<=k-1;i++){
			s+=z;
		}
	}
	c=s.size()/2;
	z=0;
	y=s.size()-1;
	while(z<=c){
		if(s[z]!=s[y]) ans++;
		z++;
		y--;
	}
	cout<<ans;

	return 0;
}
