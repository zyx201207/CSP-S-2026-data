#include<bits/stdc++.h>
using namespace std;
long long a,b,d,e;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		scanf("%d",&b);
		cin>>c;
		for(int i=1;i<=b;i++){
			s+=c;
		}
	} 
	e=(s.size()+1)/2;
	for(int i=e;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			d++;
		}
	}
	cout<<d;
	return 0;
} 


