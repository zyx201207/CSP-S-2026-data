#include<iostream>
#include<stdio.h>
using namespace std;
int c1,c2;
string a,b;
bool pd,lrc1,lrc2;
int x1,y1,x2,y2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>a>>c2>>b;
    //cout<<a<<b;
    pd=(a[0]==b[0]&&a[1]==b[1]);
    x1=a[2]-'A'+1,y1=10*(int)(a[0]-'0')+(int)(a[1]-'0');
    x2=b[2]-'A'+1,y2=10*(int)(b[0]-'0')+(int)(b[1]-'0');
        if(x1<=3) lrc1=true;
        else lrc1=false;
        if(x2<=3) lrc2=true;
        else lrc2=false;
    int pd2=(int)((x1=='C'&&x2=='D')||(x2=='D'&&x1=='C'));
    cout<<(int)(c1==c2)<<(int)(pd&&(c1==c2))<<(int)(pd&&(lrc1==lrc2)&&(c1==c2));
    cout<<(int)(y1==y2&&(abs(x1-x2)==1&&x1+x2!=7)&&c1==c2)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
