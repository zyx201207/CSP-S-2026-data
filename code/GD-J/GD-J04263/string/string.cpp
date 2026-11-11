#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,a,num;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		for(int j=1;j<=a;j++)s+=ch;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])num++;
	}
	cout<<num;
	return 0;
}//天灵灵，地灵灵，给个一等行不行！
