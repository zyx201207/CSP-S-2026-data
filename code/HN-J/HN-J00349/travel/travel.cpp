#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
const int N=10;
int ans[N]={0};
int c[]={1,2,3,4,5,6};
bool check(char x,char y){
	if(x=='C'&&y=='D'||y=='C'&&x=='D')return false;
	if(c[x-'A'+1]==c[y-'A']||c[x-'A']==c[y-'A'+1])return true;
	if(y=='D'&&x=='F'||x=='D'&&y=='F')return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string x=s1.substr(0,2),y=s2.substr(0,2);
	if(c1==c2){
		ans[1]=1;
	}
	
	
	if(x==y&&c1==c2){
		ans[2]=1;
	}
	
	if(x==y&&c1==c2&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]<='F'&&s2[2]<='F'&&s1[2]>='D'&&s2[2]>='D')){
		ans[3]=1; 
	}
	
	if(check(s1[2],s2[2])&&x==y&&c1==c2&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]<='F'&&s2[2]<='F'&&s1[2]>='D'&&s2[2]>='D')){
		ans[4]=1;
	}
	
	
	
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4]<<'\n';
	return 0;
}
