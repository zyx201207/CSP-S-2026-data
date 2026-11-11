#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long m,cnt=0;
string s;
string a;
string b,b2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>s;
		k+=m;
		for(int i=0;i<m;i++){
			a+=s;
		}
	}int l=0,r=k-1;
	while(l<r){
		if(a[l]!=a[r])cnt++;
		l++;r--;
	}
	cout<<cnt;
	return 0;
	
}
