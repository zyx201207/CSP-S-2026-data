#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	while(n--){
		long long a;
		char c;
		cin>>a;
		cin>>c;
		while(a--){
			s+=c;
		}
	}
	long long lens=s.size();
	lens/=2;
	string a,b;
	for(long long i=0;i<lens;i++){
		a+=s[i];
	}
	for(long long i=lens;i<s.size();i++){
		b+=s[i];
	}
	long long h=a.size();
	long long sum=0;
	for(long long i=0;i<h;i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	cout<<sum;
}
