#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e7 + 100;
LL x,n;
char c;
string s="";
bool prime(string s1){
	string s2="";
	for(int i=s1.size()-1;i>=0;i--)s2+=s1[i];
	if(s2==s1)return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		s+=c;
	}
	if(prime(s)){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++){
		for(char j='a';j<='z';j++){
			string qs=s;
			qs[i]=j;
			if(prime(qs)){
				cout<<"1";
				return 0;
			}
		}
	}
	return 0;
}

