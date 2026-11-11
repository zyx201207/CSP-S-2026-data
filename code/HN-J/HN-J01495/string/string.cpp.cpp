#include<bits/stdc++.h>
using namespace std;
long long n,a,l,res,r;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	r=s.size()-1;
	l=0;
	while(r>l){
		if(s[l]!=s[r]) res++;
		l++;
		r--;
	}
	cout<<res;
	return 0;
}

