#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;//a为小r车厢号，b为小X车厢号 
	string c,d;//c为小r座位号，d为小X座位号 
	int  problem1=0,problem2=0,problem3=0,problem4=0;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		problem1=1;
		if(c[0]==d[0]&&c[1]==d[1]){
			problem2=1;
			if(c[2]=='A'||c[2]=='B'||c[2]=='C'){
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
					problem3=1;
				}
			}
			else{
				if(d[2]=='F'||d[2]=='D'){
					problem3=1;
				}
				else{
					problem3=0;
				}
			}
		
			if(c[2]=='A'){
				if(d[2]=='B'){
					problem4=1;
				}
			}
			else if(c[2]=='B'){
				if(d[2]=='A'||d[2]=='C'){
					problem4=1;
				}
			}
			else if(c[2]=='C'){
				if(d[2]=='B'){
					problem4=1;
				}
			}
			else if(c[2]=='D'){
				if(d[2]=='E'){
					problem4=1;
				}
			}
			else if(c[2]=='E'){
				if(d[2]=='D'){
					problem4=1;
				}
			} 
			else problem4=0;
		}
		else problem2=0;
	}
	else problem1=0;
	cout<<problem1<<problem2<<problem3<<problem4;
	return 0;
}
