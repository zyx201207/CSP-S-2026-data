#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int sum=0;
    for(int i=0;i<2;i++){
        if(char(c1[i])==char(c2[i]))sum++;
    }
    int a=0;
    if(sum==2){
    cout<<1;
    a=1;
    }
    else cout<<0;
    sum=0;
    for(int i=0;i<2;i++){
        if(char(s1[i])==char(s2[i]))sum++;
    }
    if(a==1 && sum==2){
        cout<<1;
        a++;
    }
    else cout<<0;
    sum=0;
    if(char(s1[2])>='A' && char(s1[2])<='C' && char(s2[2])>='A' && char(s2[2])<='C') sum++;
    else if(char(s1[2])>='D' && char(s1[2])<='F' && char(s2[2])>='D' && char(s2[2])<='F') sum++;
    if(a==2 && sum==1){
        cout<<1;
        a++;
    }
    sum=0;
    else cout<<0;
    if(char(s1[2])>char(s2[2])){
        if(char(s1[2])-char(s2[i])==1) sum++;
    }
    else{
        if(char(s2[2])-char(s1[i])==1) sum++;
    }
    if(a==3 && sum==1)cout<<1;
    else cout<<0;
    return 0;
}
