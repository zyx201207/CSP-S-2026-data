#include <bits/stdc++.h>
using namespace std;
int c1,s1;
string c2,s2;
int a[15];
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if (c1==s1){
		cout<<1;
		if (c2[0]==s2[0] and c2[1]==s2[1]){
			cout<<1;
			
			if (c2[2]=='A' or s2[2]=='A') a[1]=1;
			if (c2[2]=='B' or s2[2]=='B') a[2]=1;
			if (c2[2]=='C' or s2[2]=='C') a[3]=1;
			if (c2[2]=='D' or s2[2]=='D') a[4]=1;
			if (c2[2]=='F' or s2[2]=='F') a[5]=1;
			
			for (int i=1;i<=3;i++){
				for (int j=4;j<=5;j++){
					if (a[i]==1 and a[j]==1){
						cout<<0<<0;
						return 0;
					}
				}
			}
			cout<<1;
			for (int i=1;i<=2;i++){
				if (a[i]==1 and a[i+1]==1){
					cout<<1;
					return 0;
				}
			}
			if (a[4]==1 and a[5]==1) cout<<1;
			else cout<<0;
			return 0;
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else {
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
