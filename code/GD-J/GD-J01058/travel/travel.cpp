#include<iostream>
using namespace std;
int f[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,t;
	cin>>a>>s>>b>>t;
	if(a==b) f[0]=1;
	if(f[0]==1&&s[0]==t[0]&&s[1]==t[1]) f[1]=1;
	if(f[0]==1&&f[1]==1&&(s[2]<='C')==(t[2]<='C')) f[2]=1;
	if(s[2]-t[2]==1||s[2]-t[2]==-1){
		if(f[0]==1&&f[1]==1&&f[2]==1){
			f[3]=1;
		}
	}
	for(int i=0;i<=3;i++) cout<<f[i]; 
	return 0;
} 
