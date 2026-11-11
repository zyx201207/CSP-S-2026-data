#include<bits/stdc++.h>
using namespace std;
struct d{
   int x;
   string q;
};
string s; 
d a,b;
int a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a.x>>a.q>>b.x>>b.q;
    if(a.q[0]==0){
       a1=a.q[1];
    }
    else{
       a1=a.q[0];
       a2=a.q[1];
    }
    if(b.q[0]==0){
       b1=b.q[1];
    }
    else{
       b1=b.q[0];
       b2=b.q[1];
    }
    if(a.x==b.x){
      if(a1==b1&&a2==b2){
        if(abs(a.q[2]-b.q[2])==1||abs(a.q[2]-b.q[2]==2)){
		   if(a.q[2]=='C'&&b.q[2]=='D'){	
            cout<<"1100";
        }
        else{
			if(a.q[2]=='D'&&b.q[2]=='C'){
				cout<<"1100";
				
			}
			else{
        if(abs(a.q[2]-b.q[2])==1&&a.q[2]!='C'&&b.q[2]!='D'){
					if(a.q[2]!='D'&&b.q[2]!='C'){
				 		cout<<"1111";
					}
					else{
					cout<<"1110";
				}
				}
				else{
					cout<<"1110";
				}
        }
        }
        }
        else{
        cout<<"1100";
        }
      }
      else{
        cout<<"1000";
        }
      }
      else{
      cout<<"0000";
      }
    return 0;
}
