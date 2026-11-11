#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>c>>cc>>s>>ss;
	if(c==s) cout<<1;
	else{
	cout<<"0000";
	return 0;
	}
	string a,b;
	a[0]=cc[0];
	a[1]=cc[1];
	b[0]=ss[0];
	b[1]=ss[1];
	if(a[0]==b[0]&&a[1]==b[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char e,d;
	e=cc[2];
	d=ss[2];
	if((e=='F'&&d=='D')||(e=='D'&&d=='F')){
		cout<<11;
		return 0;
	}
	if(e!='D'&&e!='F'&&d!='D'&&d!='F') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((e=='A'&&d=='B')||(d=='A'&&e=='B')||(e=='B'&&d=='C')||d=='B'&&e=='C'){
		cout<<1;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
