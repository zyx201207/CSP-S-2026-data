#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  string rx,rz,xx,xz;
  cin>>rx>>rz>>xx>>xz;
  if(rx==xx){cout<<'1';
    if(rz[0]==xz[0] and rz[1]==xz[1]){cout<<'1';
        if(rz[2]>='A' and rz[2]<='C' and xz[2]>='A' and xz[2]<='C' || rz[2]>='D' and rz[2]<='F' and xz[2]<='D' and xz[2]<='F'){cout<<'1';
            if(rz[2]+1==xz[2] || rz[2]-1==xz[2])
                cout<<'1';
                else
                cout<<'0';
        }
        else cout<<"00";
    }
    else cout<<"000";

  }
  else cout<<"0000";
return 0;
}
