#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int sum1=(c1[0]-'0')*10+(c1[1]-'0');
    int sum2=(c2[0]-'0')*10+(c2[1]-'0');
    if(sum1==sum2){
        cout<<1;
        sum1=(s1[0]-'0')*10+(s1[1]-'0');
        sum2=(s2[0]-'0')*10+(s2[1]-'0');
        if(sum1==sum2){
            cout<<1;
            if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D'){
                cout<<1;
                if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D'){
                    cout<<1;
                }else{
                    cout<<0;
                    return 0;
                }
            }else{
                cout<<0<<0;
                return 0;
            }
        }else{
            cout<<0<<0<<0;
            return 0;
        }
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}
