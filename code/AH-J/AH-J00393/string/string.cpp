#include<bits/stdc++.h>
using namespace std;
int b[26];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000005];
    char ch[1000005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>ch[i];
    }
    for(int i=1;i<=n;i++){
        if(ch[i]=='a')b[1]+=a[i];
        if(ch[i]=='b')b[2]+=a[i];
        if(ch[i]=='c')b[3]+=a[i];
        if(ch[i]=='d')b[4]+=a[i];
        if(ch[i]=='e')b[5]+=a[i];
        if(ch[i]=='f')b[6]+=a[i];
        if(ch[i]=='g')b[7]+=a[i];
        if(ch[i]=='h')b[8]+=a[i];
        if(ch[i]=='i')b[9]+=a[i];
        if(ch[i]=='j')b[10]+=a[i];
        if(ch[i]=='k')b[11]+=a[i];
        if(ch[i]=='a')b[12]+=a[i];
        if(ch[i]=='m')b[13]+=a[i];
        if(ch[i]=='n')b[14]+=a[i];
        if(ch[i]=='o')b[15]+=a[i];
        if(ch[i]=='p')b[16]+=a[i];
        if(ch[i]=='q')b[17]+=a[i];
        if(ch[i]=='r')b[18]+=a[i];
        if(ch[i]=='s')b[19]+=a[i];
        if(ch[i]=='t')b[20]+=a[i];
        if(ch[i]=='u')b[21]+=a[i];
        if(ch[i]=='v')b[22]+=a[i];
        if(ch[i]=='w')b[23]+=a[i];
        if(ch[i]=='x')b[24]+=a[i];
        if(ch[i]=='y')b[25]+=a[i];
        if(ch[i]=='z')b[26]+=a[i];
    }
    int l;
    for(int i=2;i<=26;i++)
        l=max(b[i-1],b[i]);
        cout<<l;
    return 0;
}

