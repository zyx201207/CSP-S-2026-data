#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int f1,f2,f3,f4,s,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        f1=1;
        if(c2[0]+c2[1]==c4[0]+c4[1]){
            f2=1;
            if('A'<=c2[2]<='C'&&'A'<=c4[2]<='C' || 'D'<=c2[2]<='F'&&'D'<=c4[2]<='F'){
                f3=1;
                s=max(int(c2[2]),int(c4[2]));
                m=min(int(c2[2]),int(c4[2]));
                if(s-m==1)f4=1;
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
