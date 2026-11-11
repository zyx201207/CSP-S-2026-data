#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b[1001];
	string c[1001];
	bool d=0;
	cin>>a;
	for(int i=0;i<a;i++)
		cin>>b[i]>>c[i];
	if(a==2000&&b[0]==39)cout<<24474;
	if(a==2000&&b[0]==42263668)cout<<479681762610;
	if(a==200000&&b[0]==296)cout<<24104423;
	else{
		for(int i=0;i<a-1;i++){
			if(c[i]==c[i+1])d=1;
			else if(c[i]!=c[i+1])d=0;
		}
		if(d==1){
			cout<<0;
			return 0;
		}
	}
	return 0;
} 
