#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string s1,s2;
    cin>>n>>s1>>m>>s2;
    if(n==m){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'&&s1[2]!=s2[2]||s1[2]<='E'&&s1[2]>='D'&&s2[2]<='E'&&s2[2]>='D'){
                if(s2[2]=='D'&&s1[2]=='C'||s2[2]=='C'&&s1[2]=='D'){
                    //if(s1[2]=='C'||s1[2]=='D'&&s2[2]=='C'||s2[2]=='D'){
                        //cout<<"1110"<<endl;
                    //}else
                    if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) cout<<"1111"<<endl;
                    else cout<<"1110"<<endl;
                }else if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) cout<<"1111"<<endl;
                    else cout<<"1110"<<endl;
            }else cout<<1100<<endl;
        }else cout<<"1000"<<endl;
    }else cout<<"0000"<<endl;
    return 0;
}
