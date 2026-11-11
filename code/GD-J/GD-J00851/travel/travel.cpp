#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m;
map<char,int> mp;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>a>>m>>b;
    mp['D']=mp['F']=1;
    mp['A']=mp['B']=mp['C']=2;
    if(n==m){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    int aa,bb;
    aa=a[0]-'0'+(a[1]-'0')*10;
    bb=b[0]-'0'+(b[1]-'0')*10;
    if(aa==bb){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    char c,d;
    c=a[2];
    d=b[2];
    if(mp[c]==mp[d]){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        return 0;
    }
    if(c>d)swap(c,d);
    if(c=='A'&&d=='B'){
        cout<<1;
        return 0;
    }else{
        cout<<0;
        return 0;
    }
    if(c=='B'&&d=='C'){
        cout<<1;
        return 0;
    }else{
        cout<<0;
        return 0;
    }
    if(c=='D'&&d=='F'){
        cout<<1;
        return 0;
    }else{
        cout<<0;
        return 0;
    }
}
/*
你是信的开头诗的内容童话的结尾
你是理所当然的奇迹
你是月色真美
你是圣诞老人送给我
好孩子的礼物
你是三千美丽世界里
我的一瓢水
所以让我再靠近一点点
因为你太温暖
我会再变得坚强一点点
因为你太柔软
交换无名指金色的契约
给彼此岁月
说好从今以后都牵着手
因为要走很远

洛谷关注uid1063830谢谢喵

T1读题后8:50直接切
*/
