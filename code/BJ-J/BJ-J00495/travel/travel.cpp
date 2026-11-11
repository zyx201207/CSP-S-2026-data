#include<bits/stdc++.h>
#define int long long
using namespace std;
char s1[10]="",s2[10]="";
int c1,c2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s2[1]==s1[1]){
            cout<<1;
            char str1=s1[2],str2=s2[2];
            if(str1>='A'&&str1<='C'&&str2>='A'&&str2<='C'){
                cout<<1;
                if(str1=='A'&&str2=='B')cout<<1;
                else if(str1=='B'&&str2=='C')cout<<1;
                else if(str1=='B'&&str2=='A')cout<<1;
                else if(str1=='C'&&str2=='B')cout<<1;
                else cout<<0;
            }
            else if(str1>='D'&&str1<='F'&&str2>='D'&&str2<='F'){
                cout<<1;
                if(str1=='D'&&str2=='F')cout<<1;
                else if(str1=='F'&&str2=='D')cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    cout<<'\n';
    return 0;
}
