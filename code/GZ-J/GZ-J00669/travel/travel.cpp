//GZ-J00669 ¸¶ÜÆÏª 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[4];
	char b[4];
	int a1,b1;
	cin>>a1;
	for (int i=0;i<3;i++){
		cin>>a[i];
	}
	cin>>b1;
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	if(a1==b1){
		cout<<1;
		if(a[0]==b[0] && a[1]==b[1]){
			cout<<1;
			if(a[2]=='A' || a[2]=='B' || a[2]=='C' && b[2]=='A' || b[2]=='B' || b[2]=='C'){
				cout<<1;
				if(a[2]=='A' && b[2]=='B' || a[2]=='B' && b[2]=='C' ||b[2]=='A' &&a[2]=='B' ||b[2]=='B' && a[2]=='C'||a[2]=='D'&&b[2]=='F'||b[2]=='D'&&a[2]=='F'){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else if(a[2]=='D' || a[2]=='F' && b[2]=='D' || b[2]=='F'){
				cout<<1;
				if(a[2]=='A' && b[2]=='B' || a[2]=='B' && b[2]=='C' ||b[2]=='A' &&a[2]=='B' ||b[2]=='B' && a[2]=='C'||a[2]=='D'&&b[2]=='F'||b[2]=='D'&&a[2]=='F'){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
}
