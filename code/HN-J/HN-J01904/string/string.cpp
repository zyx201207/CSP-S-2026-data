#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n];
	char c[n];
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		while(a[i]--){
			s+=c[i];
		}
	}
	long long cnt=0;
	for(size_t i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
/*
QWQ QWQ QWQ QWQ QWQ QWQ QWQ QWQ QWQ QWQ QWQ
68tps
还有一个正解没写出来 QWQ 
*/
