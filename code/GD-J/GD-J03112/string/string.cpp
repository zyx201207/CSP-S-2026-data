#include<bits/stdc++.h>
using namespace std;
long long n,a1,t,c;
char b;
string a;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.ans","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>b;
		for(int j=0;j<c;j++){
			a[t]=b;
			t++;
		}
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[t-i]){
			a1++;
		}
	}
	cout<<a1;
	return 0;
}

