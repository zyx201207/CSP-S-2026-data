#include<bits/stdc++.h>
using namespace std;
int n,a,num;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
			}
		}
	int m=0;
	n=s.size()-1;
	while(n>=m){
		if(s[n]!=s[m]) num++;
		n--;
		m++;
		}
		cout<<num;
	}
