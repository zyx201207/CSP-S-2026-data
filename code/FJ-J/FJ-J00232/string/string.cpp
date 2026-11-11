#include<bits/stdc++.h>
using namespace std;
long long n,r=0,l1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long> l(n);
	vector<char> c(n),s;
	for(int i=0;i<n;i++){
		cin>>l[i]>>c[i];
		l1=(i==0)?l[i]:(l1+l[i]);
		s.resize(l1,c[i]);
	}
	for(int i=l1/2;i<l1;i++){
		if(s[i]!=s[l1-1-i]){
			r++;
		}
	}
	cout<<r;
	return 0;
}
