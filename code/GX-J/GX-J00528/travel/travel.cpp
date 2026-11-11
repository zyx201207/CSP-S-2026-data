#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[10000]={},s1[10000]={},c2[10000]={},s2[10000]={};
    for(int i=0;i<=10000;i++){
        cin>>c1[i]>>s1[i]>>c2[i]>s2[i];
    }
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(('C'>=s1[3]>='A'&&'C'>=s2[3]>='A')||('E'>=s1[3]>='D'&&'D'>=s2[3]>='E')){
                cout<<"1";
                if((s1[3]-s2[3])==1||(s2[3]-s2[3])==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        else{
            cout<<"000";
        }
        }
    }

    else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
