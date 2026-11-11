#include<bits/stdc++.h>
using namespace std;
string s;
long long n,z=0,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	m=s.size();
	for(int i=0;i<m/2;i++){
		if(s[i]==s[m-i-1]){
			continue;
		}else{
			z++;
		}
	}cout<<z;
	return 0;
}
