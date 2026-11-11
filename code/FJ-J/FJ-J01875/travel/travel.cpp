#include<bits/stdc++.h>
using namespace std;
string s1,s2;int c1,c2;
char zt[100],ty[100],zr[100],zx[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=100;i++){
	cin>>zt[i]>>ty[i]>>zr[i]>>zx[i]; 
	}
	if(zt[0]==zr[0]&&zt[1]==zr[1])cout<<"1";
	else cout<<"0";
    if(ty[0]==zx[0]&&ty[1]==zr[1])cout<<"1";
	else cout<<"0";
	if(ty[2]<='C'&&zx[2]<='C')cout<<"1";
	if(ty[2]>='D'&&zx[2]>='D')cout<<"1";
	else cout<<"0";
	if(ty[2]-zx[2]==1||zx[2]-ty[2]==1)cout<"1";
	else cout<<"0";
	return 0;
}
