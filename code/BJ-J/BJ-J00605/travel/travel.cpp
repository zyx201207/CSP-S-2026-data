#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
    int x1,y1;
    char x2[3],y2[3];
    cin>>x1;
    for(int i=0;i<3;i++)cin>>x2[i];
    cin>>y1;
    for(int i=0;i<3;i++)cin>>y2[i];
    if(x1==y1){
       cout<<1;
       if(x2[0]==y2[0]&&x2[1]==y2[1]){
         cout<<1;
          if(x2[2]=='F')x2[2]='E';
          if(y2[2]=='F')y2[2]='E';
          if((y2[2]<=67&&x2[2]<=67)||(y2[2]>67&&x2[2]>67)){
               cout<<1;
              if(abs(y2[2]-x2[2])==1)cout<<1;
               else cout<<0;
           }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
 //system("pause");
    return 0;
}
