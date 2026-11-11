#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s;
long long i;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	n=s.size();
	while(n>s.size()/2){
		if(s[n-1]!=s[s.size()-n]){
			sum++;
		}
		n--;
	}
	cout<<sum;
	return 0;
}
