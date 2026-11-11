#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a,n;
unsigned long long sum;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++)
			s+=c;
	}
	for(int i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-1-i])
			sum++;
	cout<<sum;
	return 0;
}
