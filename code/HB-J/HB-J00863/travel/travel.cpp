#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int b1,b2,b3,b4;
void check(){
    if(c1!=c2)return;
    else b1=1;
    int l1=0,l2=0;
    for(int i=0;i<2;i++){
        l1=l1*10+s1[i];
        l2=l2*10+s2[i];
    }
    if(l1!=l2)return;
    else b2=1;
    char a1=s1[2],a2=s2[2];
    if((a1=='A'&&(a2=='B'||a2=='C'))||(a1=='B'&&(a2=='A'||a2=='C'))||(a1=='C'&&(a2=='B'||a2=='C')))b3=1;
    else if((a1=='D'&&a2=='F')||(a1=='F'&&a2=='D')){
        b3=1;
        b4=1;
        return;
    }
    if(!b3)return;
    if((a1=='A'&&a2=='B')||(a1=='B'&&(a2=='A'||a2=='C'))||(a1=='C'&&a2=='B'))b4=1;
    else b4=0;
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    check();
    printf("%d%d%d%d\n",b1,b2,b3,b4);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
