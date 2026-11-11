#include<iostream>
using namespace std;
unsigned long long n,pyl;
struct duan{
    int a;
    char c;
}d[200007],d2[200007];
string s;
unsigned long long maxn=0;
//int a[200007];
//char c[200007];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i].a>>d[i].c;
         d2[n-i+1].a=d[i].a;
        d2[n-i+1].c=d[i].c;
       maxn=max(maxn,1ull*d[i].a);
    }
    if(n*maxn<=500000){
        for(int i=1;i<=n;i++){
           for (int j=1;j<=d[i].a;j++){
                s+=d[i].c;
           }
        }
     //   cout<<s<<endl;
        for(int i=0;i<s.size()/2+1;i++){
            if(s[i]!=s[s.size()-i]){
                pyl++;
            }
        }
        cout<<pyl;
    }
    else{
        for(int i=1;i<=n;i++){
    //    cout<<d[i].c<<d2[i].c<<endl;
        if(d[i].c!=d2[i].c){
            pyl+=abs(d[i].a+d2[i].a);
    //cout<<pyl<<endl;
        }
    }
    cout<<pyl/4;
    }
    return 0;
}
/*
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。
*/
