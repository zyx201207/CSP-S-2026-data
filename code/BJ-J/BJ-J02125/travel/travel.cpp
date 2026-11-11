#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    int x=0,y=0;
    char c1,c2;
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            x=x*10+s1[i]-'0';
        }else{
            c1=s1[i];
            break;
        }
    }
    for(int i=0;s2[i]!='\0';i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            y=y*10+s2[i]-'0';
        }else{
            c2=s2[i];
            break;
        }
    }
    map<char,int>mp;
    mp['A']=0;
    mp['B']=0;
    mp['C']=0;
    mp['D']=1;
    mp['F']=1;
    if(a==b){
        cout<<1;
        if(x==y){
            cout<<1;
            if(mp[c1]==mp[c2]){
                cout<<1;
                if(abs(int(c1-c2))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
