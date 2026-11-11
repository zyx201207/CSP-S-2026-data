#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f[6]={0,0,0,1,0,1};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string t1=s1.substr(0,1),t2=s2.substr(0,1);
        if(t1==t2){
            cout<<1;
            if(f[s1[s1.size()-1]-'A']==f[s2[s2.size()-1]-'A']){
                cout<<1;
                if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1||s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F'||s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='D') cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
