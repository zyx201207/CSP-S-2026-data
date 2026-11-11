#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4,ans;
signed main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s2>>s3>>s4;
    char a=s2[2],b=s4[2];
    int x=s1[0]-'0'*10+s1[1]-'0',y=s2[0]-'0'*10+s2[1]-'0';
    int c=s3[0]-'0'*10+s1[1]-'0',d=s4[0]-'0'*10+s4[1]-'0';
    cout<<a" "<<b;
    if(x!=c) cout<<0000;
    else{
        if(y!=d){
            cout<<1000;
        }else{
            if(a>='A'&&a<='C'){
                if(b=='D'||b=='F'){
                    cout<<1100;
                }
            }else if(b>='A'&&b<='C'){
                if(a=='D'||a=='F'){
                    cout<<1100;
                }
            }else{
                if(a=='D'||a=='F'){
                    cout<<1111;
                }else{
                    char z=a+1,f=a-1;
                    cout<<f<<" "<<z;
                    if(b==z||b==f){
                        cout<<1111;
                    }else{
                        cout<<1110;
                    }
                }
            }
        }
    }
    return 0;
}
