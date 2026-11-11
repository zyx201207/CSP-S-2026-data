#include<bits/stdc++.h>
using namespace std;
string c,s,x,y;
long long a[100]={0,0,0,0,0,0,0};
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>c>>s>>x>>y;
	if(c[0]==x[0]&&c[1]==x[1]){
		a[1]=1;
	}
	if(a[1]==1){
		if(s[0]==y[0]&&s[1]==y[1]){
			a[2]=1;
		}
	}
	if(a[2]==1){
		if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
			if(y[2]=='A'||y[2]=='B'||y[2]=='C'){
				a[3]=1;
			}
		}
		if(s[2]=='D'||s[2]=='F'){
			if(y[2]=='D'||y[2]=='F'){
				a[3]=1;
			}
		}
	}
	if(a[3]==1){
		if(s[2]=='D'||s[2]=='F'){
			a[4]=1;
		}
		else{
			if(s[2]=='A'&&y[2]=='B'){
				a[4]=1;
			}
			if(s[2]=='B'&&(y[2]=='A'||y[2]=='C')){
				a[4]=1;
			}
			if(s[2]=='C'&&y[2]=='B'){
				a[4]=1;
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}
