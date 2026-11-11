#include<bits/stdc++.h>
using namespace std;
#define LL long long

inline LL read(){
    char ch=getchar();
    LL p=0;
    int w=1;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline int readI(){
    char ch=getchar();
    int p=0;
    int w=1;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void writeI(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}

unordered_map<char,bool>mp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    mp['A']=mp['B']=mp['C']=1;

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1!=c2){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if(s1.substr(0,2)!=s2.substr(0,2))cout<<"000";
        else{
            cout<<"1";
            if(mp[s1[2]]!=mp[s2[2]])cout<<"00";
            else{
                cout<<"1";
                if((int)s1[2]+1==(int)s2[2]||(int)s1[2]==(int)s2[2]+1)cout<<"1";
                else cout<<"0";
            }
        }
    }
    return 0;
}
