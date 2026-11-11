#include<bits/stdc++.h>
using namespace std;
int num(string s){
	int a=s[0]-48;
	int b=s[1]-48;
	int ans=a*10+b;
	return ans;
}
int letter(string s){
	int c=s[2];
	return c;
}
int ce(char c){
	if(c=='A' || c=='B' || c=='C'){
		return 1;
	}else return 2;
}
int ans[4]={0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++)ans[i]=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(num(c1)==num(c2)){
		ans[0]=1;
		if(num(s1)==num(s2)){
			ans[1]=1;
			if(ce(letter(s1))==ce(letter(s2) )){
				ans[2]=1;
				if(letter(s1)+1==letter(s2) || letter(s1)-1==letter(s2)){
					ans[3]=1;
				}
			}
		}
	}		
	for(int i=0;i<4;i++)cout<<ans[i];
	return 0;
}
