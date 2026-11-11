#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<c1.size();i++){
        for(int i=0;i<s1.size();i++){
            if(c1==s1){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    for(int i=0;i<c2.size();i++){
        for(int i=0;i<s2.size();i++){
            if(i==3 && j==3){
                if(c2[i]+1==s2[j] || c[i]==s[j]+1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                if(c2[i]==s2[i]){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
        }
    }
    return 0;
}
    return 0;
}
