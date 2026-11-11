#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,f=0;
    char s1[5],s2[5],S1[10]="ABBCDF0",S2[10]="BACBFD0";
    cin>>a>>s1>>b>>s2;
    if(a==b){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]=='F'&&s2[2]=='D')||(s2[2]=='D'&&s2[2]=='F')){
                    cout<<1;
                    for(int i=0;i<6;i++)if(s1[2]==S1[i]&&s2[2]==S2[i])f=1;
                    if(f)cout<<1;
                    else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;


}
