#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("traval.in","r",stdin);
freopen("traval.out","w",stdout);
string n1,m1,n2,m2;
int n3,m3;
cin>>n1>>n2>>m1>>m2;
if(n1[1]==m1[1]&&n1[0]==m1[0])
    cout<<1;
else{
        cout<<0;
    }
if(n2[0]==m2[0]&&n2[1]==m2[1])
{
    cout<<1;
}
else{
    cout<<0;

}
if(n2[2]>'A'-1&&n2[2]<'C'+1)
    n3=1;
if(n2[2]=='D'||n2[2]=='F')
    n3=2;
if(m2[2]>='A'&&m2[2]<='C')
    m3=1;
if(m2[2]=='D'||m2[2]=='F')
    m3=2;
    if(n3==m3)
        cout<<1;
    else{
        cout<<0;
    }
    if(n3==m3&&n2[2]+1==m2[2])
        cout<<1;
    if(n3==m3&&n2[2]-1==m2[2])
        cout<<1;
        else{
            cout<<0;
        }
fclose(stdin);
fclose(stdout);
return 0;
}