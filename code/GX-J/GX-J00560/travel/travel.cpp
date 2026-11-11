#include<bits/stdc++.h>
using namespace std;
int z[1000],b[1000],x,y;
int c,a;
int main(){
    freopen("travel","r".in);
    freopen("travel","w".out);
for(int i;i<=z[x];i++){
   cin>>c>>z[x]>>a;
    for(int j;j<=b[y];j++){
        cin>>b[y];
     if(c==a){
        if(z[i]==b[j])
            cout<<"1111";
            else if(z[i]==b[j+1])
                cout<<"1110";
            else if(z[i]==b[j+1==92])
                cout<<"1100";
     }

if(c==a+1){
    cout<<"0000";
}
}
return 0;
}
}
