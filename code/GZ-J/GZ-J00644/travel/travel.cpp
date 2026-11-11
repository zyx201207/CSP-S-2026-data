//罗煜坤 GZ-J00644 贵阳市第三实验中学
#include<bits/stdc++.h> 
using namespace std;
int n,n1,b,b1;
string a,a1;
char c,c1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>n1>>a1;
	if(n==n1){
		cout<<1;
		b=(a[0]-48)*10+a[1]-48,b1=(a1[0]-48)*10+a1[1]-48;
		if(b==b1){
			cout<<1;
			c=a[2],c1=a1[2];
			if((c<'D' and c1<'D') or(c>'C' and c1>'C')){
				cout<<1;
				if((c=='D' and c1=='F') or (c=='F' and c1=='D'))cout<<1;
				else if(((c-65)==(c1-64) or((c-64)==(c1-65))))cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
