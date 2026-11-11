#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,x1,x2;
    cin>>c1>>c2>>x1>>x2;
    int a=0,b=0,m=0,n=0;
    for(int i=0;i<3;i++)
    {
        if(i==0)
        {
           a=a+10*(c2[i]-'0');
           b=b+10*(x2[i]-'0');
           //cout<<a<<" "<<b<<endl;
        }
        if(i==1){
            a=a+(c2[i]-'0');
            b=b+(x2[i]-'0');
            //cout<<a<<" "<<b<<endl;
        }
        if(i==2)
        {
            if(c2[2]-'0'==17||c2[2]-'0'==18||c2[2]-'0'==19)
            {
                m=1;
            }
            else{
            m=2;
            }
            if(x2[2]-'0'==17||x2[2]-'0'==18||x2[2]-'0'==19)
            {
                n=1;
            }
            else{
                n=2;
            }
        }
    }
    //cout<<a<<" "<<b<<" "<<m<<" "<<n<<endl;
        if(c1==x1){
            cout<<"1";
        }
        else{
            cout<<"0000";
            return 0;
        }

        if(a==b)
        {
        cout<<"1";
        if(m==n)
        {
            cout<<"1";
        if(c2[2]-x2[2]==1||c2[2]-x2[2]==-1)
        {
        cout<<"1";
        }
        else{
        cout<<"0";
        return 0;
            }
        }
        else{
        cout<<"00";
        return 0;
        }
        }
        else{
            cout<<"000";
            return 0;
        }

}

