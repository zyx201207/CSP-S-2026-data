#include<bits/stdc++.h>
using namespace std;
int a,b;
char c;
string s;
int idx=0,d=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b>>c;
		for(int j=1;j<=b;j++){
			s[idx]=c;
			idx++;
		}
	}
	for(int i=0;i<idx/2;i++){
		if(s[i]!=s[idx-1-i]){
			d++;
		}
	}
	cout<<d;
	return 0;
}
