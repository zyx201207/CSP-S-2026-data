#include<bits/stdc++.h>
using namespace std;

long long int ans,n,a;
char c;
string s;
long long l;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s=' ';
	cin>>n;
	while(n--){
		cin>>a;
		cin>>c;
		while(a--){
			s+=c;
		}
	}
	l=s.size()/2;
	int i=1,j=s.size()-1;
	while(l--){
		if(s[i]!=s[j]){
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}
