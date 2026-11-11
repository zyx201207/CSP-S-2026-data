#include<bits/stdc++.h>
using namespace std;
long long n,z,a;
string b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int l=1;l<=a;l++){
			c+=b;
		}
	}
	long long l=c.size()-1;
	for(int i=0;i<c.size()/2;i++){
		if(c[i]!=c[l]){
			c[l]=c[i];
			z++;
		}
		l--;	
	}
	cout<<z;
	return 0;
}
