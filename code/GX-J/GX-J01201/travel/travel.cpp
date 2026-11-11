#include <bits/stdc++.h>

using namespace std;
int s1,s2,s3,s4;
int main()
{
    freopen("travelin","r",stdin);
    freopen("travelout","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        s1=1;
        if(b[0]==d[0]&&b[1]==d[1])
        {
            s2=1;
            if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
            {
                s3=1;
                if(b[2]+1==d[2]||d[2]+1==b[2])
                    s4=1;
            }
            else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
            {
                s3=1;
                s4=1;
            }
        }
    }
    cout<<s1<<s2<<s3<<s4;


    return 0;
}
