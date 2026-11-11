#include<bits/stdc++.h>
using namespace std;
struct per
{
    char bx[3];
    char pi[3];
    char st;
};
per R,X;
bool checks(char n[3],char m[3])
{
	if((n[0]==m[0])&&(n[1]==m[1])) return true;
	else return false;
}
bool check(char a,char b)
{
    if((a-'A'<=2)&&(b-'A'<=2)) return true;
    else if((a-'A'>=3)&&(b-'A'>=3)) return true;
    else return false;
}
bool check1(char c,char d)
{
    if((c-'A'+1)==(d-'A')) return true;
    else if((c-'A'-1)==(d-'A')) return true;
    else return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<2;i++) cin>>R.bx[i];
    for(int i=0;i<2;i++) cin>>R.pi[i];
    cin>>R.st;
    for(int i=0;i<2;i++) cin>>X.bx[i];
    for(int i=0;i<2;i++) cin>>X.pi[i];
    cin>>X.st;
    if(!checks(R.bx,X.bx)) cout<<0<<0<<0<<0;
    else if(!checks(R.pi,X.pi)) cout<<1<<0<<0<<0;
    else if(!check(R.st,X.st)) cout<<1<<1<<0<<0;
    else if(!check1(R.st,X.st)) cout<<1<<1<<1<<0;
    else cout<<1<<1<<1<<1;
    return 0;
}
