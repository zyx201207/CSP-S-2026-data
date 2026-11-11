#include<bits/stdc++.h>
using namespace std;
int c1,c2,n1,n2;
char s1,s2;
bool f1=1,f2=1,f3=1,f4=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>n1>>s1>>c2>>n2>>s2;
	if(c1==c2){
		if(n1==n2){
			if((('A'<=s1&&s1<='C'&&'A'<=s2&&s2<='C')||('D'<=s1&&s1<='F'&&'D'<=s2&&s2<='F'))){
				if(s1<s2){
					if(!((s1+1)==s2)) f4=0;
				}
				else if(s1>s2){
					if(!((s2+1)==s1)) f4=0;
				}
			}
			else f3=0;
		}
		else f2=0;
	}
	else f1=0;
	if(f1==0) cout<<"0000";
	else if(f2==0) cout<<1000;
	else if(f3==0) cout<<1100;
	else if(f4==0) cout<<1110;
	else cout<<1111;
	return 0;
}

