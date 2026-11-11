#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	char a[4],b[4];
	cin>>a1;
	for(int i=0;i<4;i++)a[i]=getchar();
	cin>>b1;
	for(int i=0;i<4;i++)b[i]=getchar();
	if(a1!=b1)cout<<"0000";
	if(a1==b1){
		if(a[1]!=b[1] or a[2]!=b[2])cout<<"1000";
		if(a[1]==b[1] and a[2]==b[2]){
			if((a[3]=='D' or a[3]=='E') and (b[3]=='D' or b[3]=='E'))cout<<"1111";
			else if(a[3]>='A' and a[3]<='C' and b[3]>='A' and b[3]<='C'){
				if((a[3]=='A' and b[3]=='B') or (a[3]=='B' and b[3]=='C'))cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
	return 0;
}
