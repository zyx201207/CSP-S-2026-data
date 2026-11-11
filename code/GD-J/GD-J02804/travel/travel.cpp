// redirected? yes
// undebugged? yes

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//#define debug // redirected when off

bool ans[4]={false,false,false,false};

bool side(char a,char b){
//    cout<<a<<' '<<b<<'\n';
    if('A'<=a&&a<='C'&&'A'<=b&&b<='C')return true;
    if((a=='D'||a=='F')&&(b=='D'||b=='F'))return true;
    return false;
}

bool quiteClose(char a,char b){
    char mi=min(a,b),ma=max(a,b);
    if(mi=='A'&&ma=='B')return true;
    if(mi=='B'&&ma=='C')return true;
    if(mi=='D'&&ma=='F')return true;
    return false;
}

int main(){
    #ifndef debug
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif // debug
    freopen("travel.in","r",stdin);

    string cage1,seat1,cage2,seat2;
    cin>>cage1>>seat1>>cage2>>seat2;

    //same cage?
    if(cage1==cage2){
        ans[0]=true;

        //same row?
//        cout<<seat1.substr(0,2)<<' ';
        if(seat1.substr(0,2)==seat2.substr(0,2)){
            ans[1]=true;

            //same side?
            if(side(seat1[2],seat2[2])){
                ans[2]=true;

                if(quiteClose(seat1[2],seat2[2])){
                    ans[3]=true;
                }
            }
        }
    }

    for(int i=0;i<4;++i)cout<<(ans[i])?1:0;
    cout<<'\n';
    return 0;
}
