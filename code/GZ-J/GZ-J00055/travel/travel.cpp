//GZ-J00055 李汭曦
#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string b1,d1,b2,d2,d3,b3;
	b1=b[0];d1=d[0];
	b3=b[1];d3=d[1];
    b2=b[2];d2=d[2];
    if(a==c){
        cout<<1;
      if(b1==d1&&b3==d3){
            cout<<1;
           if((b2>="D"&&b2<="E"&&d2>="D"&&d2<="E")||(b2>="A"&&b2<="C"&&d2>="A"&&d2<="C")){
                cout<<1;
               if((b2=="A"&&d2=="B")||(b2=="B"&&d2=="A")||(b2=="B"&&d2=="C")||(b2=="C"&&d2=="b")||(b2=="D"&&d2=="E")||(b2=="E"&&d2=="D")){
                    cout<<1;
                    return 0;
            }else{
                    cout<<"0";
                    return 0;
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
	return 0;
}
