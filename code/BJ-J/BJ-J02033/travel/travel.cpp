#include <bits/stdc++.h>

using namespace std;
int a,b;
string s1,s2;
bool visit[5];
int stu(string a){
    return (a[0]-'0')*10+(a[1]-'0');
}
bool panduan(char c1,char c2){
    int x=c1-'A';
    int y=c2-'A';
    visit[x]=1;
    visit[y]=1;
    for(int i=1;i<5;i++){
        if(visit[i]==1&&visit[i-1]==1)
            return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    int n1=stu(s1);
    char c1=s1[2];
    int n2=stu(s2);
    char c2=s2[2];
    if(n1==n2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D'))
        cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(panduan(c1,c2)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
