//GZ-J00089,遵义市第十九中学,林嘉乐
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin_niyc(0);
	string s,s1,c,c1;
	cin>>c>>s>>c1>>s1;
	char a[4]={0};
	if(c!=c1){
		cout<<a[4];
	}
	else{
		a[0]='1';
	}
	for(int i=0;i<s.size();i++){
		if((s[i]>='0'&&s[i]<='9')&&(s1[i]>='0'&&s1[i]<='9')){
			if(s[i]==s1[i]){
				a[1]='1';
			}
		}
		else{
			if((s[i]>='A'&&s[i]<='C')&&(s1[i]>='A'&&s1[i]<='C')||(s[i]>='D'&&s[i]<='F')&&(s1[i]>='D'&&s1[i]<='F')){
				a[2]='1';
			}
			else if(s[i]+1==s1[i]||s[i]-1==s1[i]){
				a[3]=='1';
			}
		}
		
	}
	cout<<a[4];
	return 0;
}
