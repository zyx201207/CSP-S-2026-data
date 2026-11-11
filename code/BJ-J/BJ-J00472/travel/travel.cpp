#include<bits/stdc++.h>
using namespace std;
int xa,pa,xb,pb,a[5]={0};
char ba,bb,c[10]={'A','B','C','D','E'};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>xa>>pa>>ba>>xb>>pb>>bb;
    //cout<<c[0]<<ba<<endl;
    if(xa==xb){
        a[1]=1;
        if(pa==pb){
            a[2]=1;
            if((ba<'D'&&bb<'D')||(ba=='D'&&bb>'D')||(ba>'D'&&bb=='D')){
                a[3]=1;
                if((c[0]==ba&&c[1]==bb)||(c[0]==bb&&c[1]==ba)||(c[2]==ba&&c[1]==bb)||(c[1]==ba&&c[2]==bb)||(c[3]==ba&&c[4]==bb)||(c[4]==ba&&c[3]==bb)){
                    a[4]=1;
                }
                //cout<<(ba==c[0])<<endl;
            }
        }else{
            a[2]=0;
        }
    }else{
        for(int i=1;i<=4;i++){
            cout<<a[i];
        }
        return 0;
    }

    for(int i=1;i<=4;i++){
        cout<<a[i];
    }
    return 0;
}