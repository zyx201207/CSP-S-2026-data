#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt,w[200005];
vector<string> r;
string er(long long x){
	string l;
	long long p,k=0;
	while(x>=1){
		l[k]=x%2+'0';
		x/=2;
		k++;
	}
	return l;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m!=n){
		cout<<a[n-m];
	}
}
