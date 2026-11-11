#include<iostream>
using namespace std;
int s[200005];
string a,b;
long long m=0,o=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long d=0;
	for(int i=0;i<n;i++){
		cin>>s[i]>>b[i];
		for(int j=0;j<s[i];j++,d++){
			a[d]=b[i];
		}
		m+=s[i];
	}
	for(int j=0;j<m/2;j++){
		if(a[j]!=a[m-j-1])o++;
	}
	cout<<o;
	return 0;
}
