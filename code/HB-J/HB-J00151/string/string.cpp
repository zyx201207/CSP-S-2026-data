#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,zds=0,cd=0;
    cin >> a;
    int d[a+5];
    string c,wzd,zdsz;
    for(int i=1;i<=a;i++){
        cin >> b >> c;
        for(int j=1;j<=b;j++) wzd+=c;
        cd+=b;
        d[i] = b;
        if(d[i]>=zds){
            zds=b;
            zdsz=c;

        }

    }
    cout << cd-zds;
    //if(cd%2==1){
     //       if(wzd[cd/2+1]==zdsz){
    //            cout << cd-zds-1;
     //       }else{
    //        cout << cd-zds+1;}
//
 //   }else{
  //      if(wzd[cd/2]==wzd[cd/2+1]){
  //          if(wzd[cd/2]==zdsz){
   //             cout << cd-zds;
    //        }else{
   //             cout << cd-zds-2;
     //       }
  //      }else if(zdsz==wzd[cd/2] || zdsz==wzd[cd/2+1]){
 //           cout << cd-zds;
   //     }else{
  //      cout << cd-zds+2}
  //  }

}
