#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2;
	char a[10],b[10];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1;
    
    for(int i=1;i<=3;i++){
    	cin>>a[i];
	}
	
	cin>>a2;
	
	for(int i=1;i<=3;i++){
    	cin>>b[i];
	}
	
	if(a1==a2){
		if(a[1]==b[1]&&a[2]==b[2]){
			int u=1;
			if(((a[3]=='A'||a[3]=='B'||a[3]=='C')&&(b[3]=='A'||b[3]=='B'||b[3]=='C'))){
				if(a[3]==b[3]+1||b[3]==a[3]+1){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else if(((a[3]=='D'||a[3]=='F')&&(b[3]=='D'||b[3]=='F'))){
				if(a[3]==b[3]+1||b[3]==a[3]+1){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<0000;
	}
    return 0;
}
