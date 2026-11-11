#include<bits/stdc++.h>
using namespace std;
string a[25], b[25];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=3;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	for(int i=1;i<=9;i++){
		if(a[1]==0){
			if(a[2]==i){
				int c=i;
				break;
			}
		}
		else{
			if(a[2]==i){
				int c=i+10;
			}
		}
		if(b[1]==0){
			if(a[2]==i){
				int d=i;
				break;
			}
		}
		else{
			if(int(b[2])==i){
				int d=i+10;
			}
		}
	}
	if(n==m)	cout<<1;
	else 	cout<<0;
	if(c==d)	cout<<1;
	else 	cout<<0;
	if(((a[3]=='A' || a[3]=='B' || a[3]=='C')&&(b[3]=='A' || b[3]=='B' || b[3]=='C'))||((a[3]=='D' || a[3]=='F')&&(b[3]=='D' || b[3]=='F')))	cout<<1;
	else 	cout<<0;
	if((a[3]=='A'&&b[3]=='B')||(a[3]=='B'&&(b[3]=='C'||b[3]=='A')||(a[3]=='C'&&(b[3]=='B'||b[3]=='D')||(a[3]=='D'&&(b[3]=='C'||b[3]=='F')||(a[3]=='F'&&b[3]=='D'))	cout<<1;
	else 	cout<<0;
	return 0;
}
