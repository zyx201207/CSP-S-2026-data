#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
int n1,n2;
int d1,d2;
string s1,s2;
string ans;
char c1,c2;
int read(){
    int su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    n1=read();cin>>s1;
    n2=read();cin>>s2;
    d1=s1[0]*10+s1[1];
    d2=s2[0]*10+s2[1];
    c1=s1[2],c2=s2[2];
    if(c1=='F')c1='E';
    if(c2=='F')c2='E';
    ans="0000";
    if(n1==n2){
        ans[0]='1';
        if(d1==d2){
            ans[1]='1';
            if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C')){
                ans[2]='1';
                if(abs(c1-c2)==1)ans[3]='1';
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}

