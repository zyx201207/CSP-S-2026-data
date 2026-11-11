#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a,x;
long long a[5e5+10];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	s=s[1]-s[0];
	for(int i=1;i<=m;i++){
		a+=s*i;
		if(a>=m){
			cout<<x;
			return 0;
		}
		x++;
	}
}
