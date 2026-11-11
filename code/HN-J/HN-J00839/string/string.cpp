#include <bits/stdc++.h>
using namespace std;
string s;
long long n,num;
long long a[200005];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i] >>c;
		for(long long j=1;j<=a[i];j++){
			s+=c;
		}
	}
	long long m=s.size()/2+1,x=s.size();
	for(long long i=m;i<s.size();i++){
		char c=s[i],d=s[x-i-1];
		if(c!=d){
			num++;
		}
	}
	cout <<num; 
	return 0;
}
/*
2
2 a
3 a


*/
