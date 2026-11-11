#include <bits/stdc++.h>
using namespace std;
string huiwen,cc;
long n,a;
long r=0,l=0,sum=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>cc;
		for(int j=0;j<a;j++){
			huiwen+=cc;
			sum++;
		}
	}
	l=sum-1;
	while(r<l){
		if(r==l){
			break;
		}
		if(huiwen[r]!=huiwen[l]){
			ans++;
		}
		r++;
		l--;
	}
	cout<<ans;
	return 0;
}
