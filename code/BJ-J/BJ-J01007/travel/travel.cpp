#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s3>>s2>>s4;
    char t1=s3[2],t2=s4[2];
    if(s1!=s2)printf("0000");
    else if(s3[0]!=s4[0]||s3[1]!=s4[1])printf("1000");
    else if(t1<='C'&&t2>'C'||t1>'C'&&t2<='C')printf("1100");
    else if(t1+1!=t2&&t2+1!=t1)printf("1110");
    else printf("1111");
    return 0;
    fclose(stdin);
    fclose(stdout);
}
