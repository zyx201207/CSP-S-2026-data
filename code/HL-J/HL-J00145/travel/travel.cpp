#include<bits/stdc++.h>
using namespace std;
string s,ss;
int c,cc,a,b,x,y;
bool ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	for(int i=0;i<2;i++){
		a+=a*10+s[i]-'0';
		b+=b*10+ss[i]-'0';
	}
	x=s[2]-'A';
	y=ss[2]-'A';
	if(c==cc){
		ans[0]=1;
		if(a==b){
			ans[1]=1;
			if((x<=2&&y<=2)||(x>2&&y>2)){
				ans[2]=1;
				if(abs(x-y)==1) ans[3]=1;
			}
		}
	}
	else{
		for(int i=0;i<4;i++){
			ans[i]=0;
		}
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}