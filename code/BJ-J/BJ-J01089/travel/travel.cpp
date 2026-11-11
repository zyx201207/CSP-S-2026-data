#include <bits/stdc++.h>
using namespace std;
int main(){
    //rp+=inf!!! IAKIOI!!!
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    char t1,t2;
    int c1,c2;
    bool samec,samer,sames;
    cin>>c1>>s1>>c2>>s2;
    t1=s1[2];
    t2=s2[2];
    samec=c1==c2;
    samer=(s1[0]==s2[0]&&s1[1]==s2[1]);
    sames=(t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')||(t1>='D'&&t1<='F'&&t2>='D'&&t2<='F');
    cout<<samec;
    cout<<(samer && samec);
    cout<<(sames && samec && samer);
    cout<<(samer &&((abs(t1-t2)==1&&!(t1=='C'&&t2=='D'||t1=='D'&&t2=='C'))||(t1=='D'&&t2=='F'||t1=='F'&&t2=='D')));
    return 0;
}
