#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("D:/GD-J03043/travel/travel.in" , "r" , stdin);
	freopen("D:/GD-J03043/travel/travel.out" , "w" , stdout);
	int n , m;
	string a , b;
	cin>>n>>a>>m>>b;
	int x , y;
	x=int(a[0]-48)*10+int(a[1]-48);
	y=int(b[0]-48)*10+int(b[1]-48);
	
	
	if(n==m){
		cout<<'1';
		if(x==y){
			cout<<'1';
			if(a[2]=='A' && b[2]=='B' || a[2]=='C' && b[2]=='B' || a[2]=='A' && b[2]=='C' || a[2]=='C' && b[2]=='A' || a[2]=='B' && b[2]=='A' || a[2]=='B' && b[2]=='C' || a[2]=='D' && b[2]=='F' || a[2]=='F' && b[2]=='D'){
				cout<<'1';
				if(a[2]=='A' && b[2]=='B' || a[2]=='C' && b[2]=='B' ||  a[2]=='B' && b[2]=='A' || a[2]=='B' && b[2]=='C' || a[2]=='D' && b[2]=='F' || a[2]=='F' && b[2]=='D'){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	
} 
