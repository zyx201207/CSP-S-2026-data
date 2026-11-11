#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
typedef long long ll;
ll read() {
    ll x=0,f=1;
    ll ch=gc();
    while(!isdigit(ch)) {
        if(ch=='-')f=-1;
        ch=gc();
    }
    while(isdigit(ch)) {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
void write(ll x) {
    ll stk[48],t;
    if(x<0)pc('-'),x=-x;
    if(x==0)pc('0');
    while(x)stk[t++]=x%10,x/=10;
    for(int i=t-1;i>=0;i--)pc(stk[i]^48);
    pc(' ');

}
namespace cd {
    ll co1,co2,row1,row2,col1,col2;
    // A1 B2 C3 D5 F6
    int side(ll co) {
        if(co<4)return 1;
        if(co>4)return 2;
        return -1;
    }
    int val(char c) {
        if(c=='A')return 1;
        if(c=='B')return 2;
        if(c=='C')return 3;
        if(c=='D')return 5;
        if(c=='F')return 6;
        return -1;

    }
    bool sameside() {
        return side(col1)==side(col2);
    }
    char a[20];
    int main() {
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
        for(int i=0;i<13;i++)a[i]=gc();
        co1=(a[0]^48)*10+(a[1]^48);
        co2=(a[7]^48)*10+(a[8]^48);
        row1=(a[3]^48)*10+(a[4]^48);
        row2=(a[10]^48)*10+(a[11]^48);
        col1=val(a[5]);
        col2=val(a[12]);
        //printf("%lld %lld %lld %lld %lld %lld",co1,co2,row1,row2,col1,col2);
        if(co1==co2) pc('1'); else pc('0');
        if(co1==co2&&row1==row2)pc('1'); else pc('0');
        if(co1==co2&&row1==row2&&sameside())pc('1'); else pc('0');
        if(co1==co2&&row1==row2&&sameside()&&(col1+1==col2||col1-1==col2))pc('1'); else pc('0');
        pc('\n');
        return 0;
    }
}
int main(){return cd::main();}



//Trick||Treat!
