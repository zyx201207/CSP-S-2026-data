#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans1=0,ans2=0,ans3=0,ans4=0;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]){
		if(a[1]==c[1]){
			ans1=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			ans2=1;
			if(b[2]=='A'&&d[2]=='B'){
				ans4=1;
			}
			if(d[2]=='A'&&b[2]=='B'){
				ans4=1;
			}
			if(b[2]=='B'&&d[2]=='C'){
				ans4=1;
			}
			if(d[2]=='B'&&b[2]=='C'){
				ans4=1;
			}
			if(b[2]=='D'&&d[2]=='F'){
				ans4=1;
			}
			if(d[2]=='D'&&b[2]=='F'){
				ans4=1;
			}
			if(b[2]<='C'&&d[2]<='C'){
				ans3=1;
			}
			if(b[2]<='F'&&d[2]<='F'&&b[2]>='D'&&d[2]>='D'){
				ans3=1;
			}
		}
	}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
