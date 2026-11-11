#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int a1,b1,a2,b2;
char c,d;
int main( ){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int l=c1.length();
    for(int i=0;i<l;i++){
        a1=a1*10+c1[i]-'0';
        a2=a2*10+c2[i]-'0';
        b1=b1*10+s1[i]-'0';
        b2=b2*10+s2[i]-'0';
    }
    c=s1[2],d=s2[2];
    if(a1!=a2){
        ans.push_back('0');
        ans.push_back('0');
        ans.push_back('0');
        ans.push_back('0');
    }else{
        ans.push_back('1');
        if(b1!=b2){
            ans.push_back('0');
            ans.push_back('0');
            ans.push_back('0');
        }else{
            ans.push_back('1');
            if((c<='C'&&d>='D')||(c>='D'&&d<='C')){
                ans.push_back('0');
                ans.push_back('0');
            }else{
                ans.push_back('1');
                int c11=c,c22=d;
                if((c11-c22==1)||(c22-c11==1)) ans.push_back('1');
                else ans.push_back('0');
            }
        }
    }
    for(int i=0;i<4;i++) cout<<ans[i];
    return 0;
}
