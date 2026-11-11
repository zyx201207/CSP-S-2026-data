#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
string c1,s1,c2,s2;
int a[N];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='D')s1[2]='E';
    if(s2[2]=='D')s2[2]='E';
    string S1=s1.substr(0,2),S2=s2.substr(0,2);
    bool sd1=(s1[2]<'D'),sd2=(s2[2]<'D');
    int x1=s1[2]-'A',x2=s2[2]-'A';
    if(c1==c2){
        a[1]=1;
        if(S1==S2){
            a[2]=1;
            if(sd1==sd2){
                a[3]=1;
                if(abs(x1-x2)==1){
                    a[4]=1;
                }
            }
        }
    }
    for(int i=1;i<=4;i++)printf("%d",a[i]);
    return 0;
}
