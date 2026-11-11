//GZ-J00584，盛诗尧，贵阳市清华中学 
#include<bits/stdc++.h>
using namespace std;
int r;
string R;
int x;
string X;
bool q1,q2,q3,q4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>r>>R>>x>>X;
	
	if(r==x){
		
		q1=1;
		
		int a=10*(int(R[0]))+(int(R[1]));
		int b=10*(int(X[0]))+(int(X[1]));
		
		if(a==b){
			q2=1;
			
			
			if(('A'<=R[2]<='C'&&'A'<=X[2]<='C' || 'D'<=R[2]<='F'&&'D'<=X[2]<='F') &&!((R[2]=='C'&&X[2]=='D' || R[2]=='D'&&X[2]=='C'))){
				q3=1;
				
				if(R[2]=='C'&&X[2]=='D' || R[2]=='D'&&X[2]=='C'){
					q4=0;
				}else if(R[2]=='A'&&X[2]=='B' || R[2]=='B'&&X[2]=='A' ||
						R[2]=='B'&&X[2]=='C' || R[2]=='C'&&X[2]=='B' ||
						R[2]=='D'&&X[2]=='F' || R[2]=='F'&&X[2]=='D'){
							q4=1;
					}
					else{
						q4=0;
					}
			}else{
				q3=0;
			}
		}else{
			q2=0;
		}
	}else{
		q1=0;
	}
	cout<<q1<<q2<<q3<<q4;
	return 0;
}
