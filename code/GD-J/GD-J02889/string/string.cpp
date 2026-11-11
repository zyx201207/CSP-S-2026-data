#include<bits/stdc++.h>
using namespace std;
struct num{
	long long n;
	char c;
};
bool hw(string s){
	string ss;
	for(int i=s.length()-1;i>=0;i--)ss+=s[i];
	if(ss==s)return 1;
	return 0;
}int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,b;
	char c;
	num a[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		a[i].n=b,a[i].c=c;
		for(int i=1;i<=b;i++)s+=c;
	}if(hw(s)){
		cout<<0;	
		return 0;
	}long long aa=a[1].n,bb=a[2].n;
	if(n==2)cout<<min(aa,bb);
}
