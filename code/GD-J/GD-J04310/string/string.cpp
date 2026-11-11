#include<bits/stdc++.h>
using namespace std;
long long n,a,s,r,l,sum;
char b;
string str;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		s+=a;
		while(a--){
			str+=b;
		}
	}
	r=s-1;
	while(l<r){
		if(str[l]!=str[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
} 
