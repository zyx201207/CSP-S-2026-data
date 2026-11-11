#include <bits/stdc++.h>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("string.in");
ofstream fout("string.out");
int main(){
	string s;
	string c;
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		s=s+c;
	}
	long long ans=0;
	int p=0,q=n-1;
	while(p<q){
		if(a[p]<a[q]){
			if(s[p]!=s[q]) ans+=a[p];
			a[q]-=a[p];
			p++;
		}
		if(a[p]>=a[q]){
			if(s[p]!=s[q]) ans+=a[q];
			a[p]-=a[q];
			q--;
		}
	}
	cout<<ans;
	return 0;
} 



