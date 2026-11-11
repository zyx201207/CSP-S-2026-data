#include<bits/stdc++.h>
using namespace std;
int a,b,sum,num,ans,cpp;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		sum=1;
		if(c[0]==d[0]&&c[1]==d[1]){
			num++;
			if(((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')&&c[2]!=d[2])||((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F')&&d[2]!=c[2])){
				ans=1;
				if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C')||(c[2]=='D'&&d[2]=='F')||(d[2]=='A'&&c[2]=='B')||(d[2]=='B'&&c[2]=='C')||(d[2]=='D'&&c[2]=='F')){
					cpp=1;
				}
			}
		}
	}
	cout<<sum<<num<<ans<<cpp;
	return 0;
} 
