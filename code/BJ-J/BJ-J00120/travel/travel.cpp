#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int block1,block2;
int r1,r2;
int num1,num2;
bool b1,b2,b3,b4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    block1=(c1[0]-'0')*10+(c1[1]-'0');
    block2=(c2[0]-'0')*10+(c2[1]-'0');
    if(block1==block2)
        b1=1;
    
    r1=(s1[0]-'0')*10+(s1[1]-'0');
    r2=(s2[0]-'0')*10+(s2[1]-'0');
    if(b1&&(r1==r2))
        b2=1;
    
    num1=s1[2]-'A'+1;
    num2=s2[2]-'A'+1;
    if(b1&&b2)
        if((num1<=3&&num1>=1&&num2<=3&&num2>=1)||(num1<=5&&num1>=4&&num2<=5&&num2>=4))
            b3=1;

    if(b1&&b2&&b3&&abs(num1-num2)==1)
        b4=1;

    cout<<b1<<b2<<b3<<b4<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}