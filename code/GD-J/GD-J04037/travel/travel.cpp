#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,c2;
	int s1,s2;
	char d1,d2;
	cin>>c1>>s1>>d1>>c2>>s2>>d2;
	if(c1==c2){//判断在同一车厢
		cout<<"1";
		if(s1==s2){//判断是否在同一排 
			cout<<"1";
			if(d1=='A'||d1=='B'||d1=='C'&&d2=='A'||d2=='B'||d2=='C'){//判断是否位于过道同一侧 
				cout<<"1";
				if(d1=='A'&&d2=='B'||d1=='B'&&d2=='A'||d1=='B'&&d2=='C'||d1=='C'&&d2=='B'){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(d1=='D'||d1=='F'&&d2=='D'||d2=='F'){//判断是否位于过道同一侧 
				cout<<"11";
			}
			else{
				cout<<"00"; 
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
		
	}
	return 0;
}  
