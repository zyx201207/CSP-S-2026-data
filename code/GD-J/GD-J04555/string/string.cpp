#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int j=0;
	for(int i=0;i<n;i++){
		int b;char c;
		cin>>b>>c;
		int j2=j;
		for(j;j<j2+b;j++){
			a+=c;
		}
	}
	long long m=0;
	for(int i=0;i<a.size()/2;i++){
		if(!(a[i]==a[a.size()-1-i])){
			m++;
		}
	}
	cout<<m;
	return 0;
}
