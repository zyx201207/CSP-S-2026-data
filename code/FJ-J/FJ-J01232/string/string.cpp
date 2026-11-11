#include <bits/stdc++.h>
using namespace std;
long long n;
long long a1,num,qu;
long long d=1;
char s1;
string anss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a1;
		cin>>s1;
		num+=a1;
		for(int i=1;i<=a1;i++){
			anss[d]=s1;
			d++;
		}
	}
	long long nn=num/2;
	long long l=1,r=num;
	while(nn--){
		if(anss[l]!=anss[r]){
			qu++;
		}
		l++;
		r--;
	}
	cout<<qu;
	return 0;
}
