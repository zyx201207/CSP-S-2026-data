//GZ-J00251   遵义市第五十三中学 王前进   
#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000"; return 0;
	}
	int a1=s1[2],a2=s2[2];
	
	if(s1[2]>='D'&&s2[2]>='D'){
		cout<<111;
		return 0;
	}
	else if(s1[2]>='A'&&s2[2]>='A' &&s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
		if(a1>a2&&a1==a2+1) cout<<1;
		else if(a2>a1&&a2==a1+1) cout<<1;
		else cout<<0;
	}
	else{
		cout<<0;
		if(a1>a2&&a1==a2+1) cout<<1;
		else if(a1<a2&&a1==a2-1) cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
}

