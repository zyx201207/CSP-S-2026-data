#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,sum=0;
char i,j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>i>>c>>d>>j;
	if(i=='F') i='E';
	if(j=='F') j='E'; 
	if(a==c and b==d and ((i>='A' and i<='C' and j>='A' and j<='C') or (i>='D' and j>='D')) and abs(i-j)==1) sum+=4;
	else if(a==c and b==d and (i>='A' and i<='C' and j>='A' and j<='C') or (i>='D' and j>='D')) sum+=3;
	else if(a==c and b==d) sum+=2;
	else if(a==c) sum+=1;
	for(int i=1;i<=4;i++){
		if(i<=sum) cout<<1;
		else cout<<0;
	}
	
} 
