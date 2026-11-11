#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1[5];
    string s1[5];
    string c2[5];
    string s2[5];
    for(int a=0;i<=2;a++){
        cin>>c1[a];
    }
    for(int b=0;i<=2;b++){
        cin>>c2[b];
    }
    for(int c=0;i<=2;c++){
        cin>>s1[c];
    }
    for(int d=0;i<=2;d++){
        cin>>s2[d];
    }
    string g1[5]=0;
    string g2[5]=0;
    string g3[5]=0;
    string g4[5]=0;
    if(c1[0]==c2[0]){
        g1+=1;
        if(s1[1]==s2[1]){
            g2+=1;
        }
    }
    if(s1[0]==s2[0]-1 || s1[0]==s2[0]+1 || s1[0]-1==s2[0] || s1[0]+1==s2[0]){
                g4+=1;

            }
    cout<<g1[0]<<g2[0]<<g3[0]<<g4[0]<<endl;
    return 0;
}
