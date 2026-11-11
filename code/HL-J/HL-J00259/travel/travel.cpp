#include<bits/stdc++.h>
using namespace std;
int ans1,ans2,ans3,ans4;
string c1,c2,s1,s2;
char a1,a2,b1,b2;
char r1,r2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1=1;
	}else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	a1=s1[0];
	a2=s1[1];
	b1=s2[0];
	b2=s2[1];
	if(a1==b1&&a2==b2){
		ans2=1;
	}else {
		cout<<1000;
		return 0;
	}
	r1=s1[2];
	r2=s2[2];
	if(r1>='A'&&r1<='C'&&r2>='A'&&r2<='C'||r1>='D'&&r1<='F'&&r2>='D'&&r2<='F'){
		ans3=1;
		int n=r1-r2;
		n=fabs(n);
		if(n==1){
			ans4=1;
		}
	}else if(r1>='D'&&r1<='F'&&r2>='D'&&r2<='F'){
		ans3=1;
		ans4=1;
	}else {
		cout<<1100;
		return 0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}