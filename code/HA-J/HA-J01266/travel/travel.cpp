#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
long long a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		a=1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			b=1;
			if(c1[2]=='C' || c1[2]=='B' || c1[2]=='A'){
				if(c2[2]<='C'){
					c=1;
					if(char(c1[2]+1)==c2[2] || char(c1[2]-1)<=c2[2]){
						d=1;
					}
				}
			}
			else{
				if(c2[2]>='D'){
					c=1;
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}

