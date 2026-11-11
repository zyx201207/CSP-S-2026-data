#include <bits/stdc++.h>
using namespace std;
string a,b,c;
long long n,m[200005],sum,l=0,r=n+1,f;
int main(){
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>b;
		for(int j=0;j<m[i];j++){
			a+=b;
		}
	}
	for(int i=1;i<n;i++){
		if(a[i-1]!=a[i]){
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	while(l<r){
		if(a[l]!=a[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}
