#include<bits/stdc++.h>
using namespace std;
string aa,ab,ba,bb;
bool tyc(char a,char b){
    int aaa=0,bbb=0;
    if(a=='A'||a=='B'||a=='C')aaa++;
    if(b=='A'||b=='B'||b=='C')aaa++;
    if(a=='D'||a=='F')bbb++;
    if(b=='D'||b=='F')bbb++;
    if(aaa==1&&bbb==1)return 0;
    if(aaa==2||bbb==2)return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>aa>>ab>>ba>>bb;
    //同一节车厢
    if(aa==ba)cout<<1;
    else cout<<0;
    //同一节车厢的同一排
    if(ab[0]==bb[0]&&ab[1]==bb[1]&&aa==ba)cout<<1;
    else cout<<0;
    //同一节车厢同一排同一侧
    if(ab[0]==bb[0]&&ab[1]==bb[1]&&aa==ba&&tyc(ab[2],bb[2]))cout<<1;
    else cout<<0;
    //座位是否相邻
    bool f=0;
    if(aa==ba||!(ab[0]==bb[0]&&ab[1]==bb[1])){
        cout<<0;
        return 0;
    }

    if(ab[2]=='A'&&bb[2]=='B')f=1;
    if(ab[2]=='B'&&(bb[2]=='A'||bb[2]=='C'))f=1;
    if(ab[2]=='C'&&bb[2]=='B')f=1;
    if(ab[2]=='D'&&bb[2]=='F')f=1;
    if(ab[2]=='F'&&bb[2]=='D')f=1;
    if(f)cout<<1;
    else cout<<0;

}
