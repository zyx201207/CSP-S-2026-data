#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	cout<<(a==b?1:0);
	cout<<(a1[0]==b1[0] and a1[1]==b1[1] and a==b?1:0);
	if(a1[0]==b1[0] and a1[1]==b1[1] and a==b and ((a1[2]=='A' or a1[2]=='B' or a1[2]=='C')and(b1[2]=='A' or b1[2]=='B' or b1[2]=='C'))or((a1[2]=='D' or a1[2]=='E')and(b1[2]=='D' or b1[2]=='E'))){
		cout<<1;
	}
	else cout<<0;
	if(a1[0]==b1[0] and a1[1]==b1[1] and a==b and ((a1[2]=='A' or a1[2]=='B' or a1[2]=='C')and(b1[2]=='A' or b1[2]=='B' or b1[2]=='C'))or((a1[2]=='D' or a1[2]=='E')and(b1[2]=='D' or b1[2]=='E'))){
		if(a1[2]>b1[2]?int(a1[2]-b1[2])==1:int(b1[2]-a1[2])==1){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
