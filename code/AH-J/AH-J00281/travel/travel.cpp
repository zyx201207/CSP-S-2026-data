#include<bits/stdc++.h>
using namespace std;
int ans[4];
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[1]++;
		if((b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0'){
			ans[2]++;
			if((b[2]<='C' && d[2]<='C') || (b[2]>='D' && d[2]>='D')){
				ans[3]++;
				if(b[2]=='F'||d[2]=='F'){
					if(b[2]=='D'||d[2]=='D') ans[4]++;
				}
				else{
					if(abs(b[2]-d[2])==1) ans[4]++;
				}
			}
		}
	}
	
	for(int i=1;i<=4;i++) cout<<ans[i];
	return 0;
}
