#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    fclose(stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int c[5]={0};
    if(a1==b1){
    c[0]=1;
        if(b2[0]==a2[0]&&b2[1]==a2[1]){
        c[1]=1;
            if(max(b2[2]-a2[2],a2[2]-b2[2])<=2){
                c[2]=1;
                if(max(b2[2]-a2[2],a2[2]-b2[2])<2){
                    c[3]=1;
                }
            }
        }
}
for(int i=0;i<4;i++){
cout<<c[i];
}
return 0;
}
