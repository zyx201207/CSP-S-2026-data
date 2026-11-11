#include<bits/stdc++.h>
using namespace std;
long long n,m[200005],a,b;
char c[200005];
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","m",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>c[i];
		b+=m[i];
		for(int j=0;j<m[i];j++){
			s+=c[i];
		}
	}
	if(n==1){
		cout<<0;
	}
	for(int i=0;i<=sqrt(b)-1;i++){
		s1+=s[i];
	}
	for(int i=0;i<=sqrt(b)-1;i++){
		for(int j=b-1;j>=sqrt(b);j--){
			if(s1[i]!=s[j]){
				a++;
				break;
			}
		}
	}
	cout<<a;
	return 0;
}
