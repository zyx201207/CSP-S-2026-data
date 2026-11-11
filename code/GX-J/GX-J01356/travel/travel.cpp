#include<bits/stdc++.h>
using namespace std;

int c1,c2,at1,at2;
int w[500];
char is1,is2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    w['A']=w['B']=w['C']=1;
    w['D']=w['F']=2;
    
   cin>>c1>>at1>>is1>>c2>>at2>>is2;
   if(c1==c2)cout<<"1";
   else cout<<"0";
   if(c1==c2&&at1==at2)cout<<"1";
   else cout<<"0";
   if(c1==c2&&at1==at2&&w[(int)is1]==w[(int)is2])cout<<"1";
   else cout<<"0";
   if(c1==c2&&at1==at2&&w[(int)is1]==w[(int)is2]&&abs((int)is1-(int)is2)==1)cout<<"1";
   else cout<<"0";
    return 0;
}
