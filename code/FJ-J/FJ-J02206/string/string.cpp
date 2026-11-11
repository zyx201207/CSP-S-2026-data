#include<bits/stdc++.h>
using namespace std;
long long n,h=0,an=0;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		char w;
		long long s;
		cin>>s>>w;
		for(long long j=0;j<s;j++)a+=w;
		h+=s;
	}
	for(long long i=h-1,j=0;i>(h+1)/2-1;i--,j++){
		if(a[i]!=a[j])an++;
	}
	cout<<an;
	return 0;
}

