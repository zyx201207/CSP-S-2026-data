#include<iostream>
#include<cmath>
using namespace std;

long long c1,c2;
struct node{
    long long num;
    char c;
}s1,s2;
string str;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>str;
    c1=(str[0]-'0')*10+str[1]-'0';
    cin>>str;
    s1.num=(str[0]-'0')*10+str[1]-'0';
    s1.c=str[2];
    cin>>str;
    c2=(str[0]-'0')*10+str[1]-'0';
    cin>>str;
    s2.num=(str[0]-'0')*10+str[1]-'0';
    s2.c=str[2];
    // cout<<c1<<" "<<s1.num<<s1.c<<" "<<c2<<" "<<s2.num<<s2.c;
    bool pd1=c1==c2;
    bool pd2=pd1&&s1.num==s2.num;
    bool pd3=pd2&&((s1.c<='C'&&s2.c<='C')||(s1.c>='D'&&s2.c>='D'));
    bool pd4=pd3&&abs(s1.c-s2.c<=1);
    cout<<(long long)pd1;
    cout<<(long long)pd2;
    cout<<(long long)pd3;
    cout<<(long long)pd4;
    cout<<"\n";
    return 0;
}