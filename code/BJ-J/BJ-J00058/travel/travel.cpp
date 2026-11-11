#include<bits/stdc++.h>
using namespace std;
bool sameside(string x1,string x2)
{
    if(x1[2]=='A')
    {
        if(x2[2]=='B' || x2[2]=='C')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(x1[2]=='B')
    {
        if(x2[2]=='A' || x2[2]=='C')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(x1[2]=='C')
    {
        if(x2[2]=='B' || x2[2]=='A')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(x1[2]=='D')
    {
        if(x2[2]=='F')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(x1[2]=='F')
    {
        if(x2[2]=='D')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
bool nxtto(string x1,string x2)
{
    if(!sameside(x1,x2))
    {
        return false;
    }
    else
    {
        if(x1[2]=='A' && x2[2]=='C')
        {
            return false;
        }
        else if(x1[2]=='C' && x2[2]=='A')
        {
            return false;
        }
        else
        {

            return true;
        }
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string tic1,tic2;
    cin>>a>>tic1>>b>>tic2;
    //1
    if(a==b)
    {
        cout<<'1';
    }
    else
    {
        cout<<"0000";
        return 0;
    }

    //2
    if(tic1[0]==tic2[0] && tic1[1]==tic2[1])
    {
        cout<<'1';
    }
    else
    {
        cout<<"000";
        return 0;
    }

    int n1=0,n2=0;
    n1=(tic1[0]-'0')*10+(tic1[1]-'0');
    n2=(tic2[0]-'0')*10+(tic2[1]-'0');
    //cout<<"n1:"<<n1<<" n2:"<<n2<<"\n";
    //3
    if(sameside(tic1,tic2))
    {
        cout<<'1';
    }
    else
    {
        cout<<"00";
        return 0;
    }

    //4
    if(nxtto(tic1,tic2))
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    return 0;
}
//LuoTianYi NB!
//by Luogu@HuangRuibo uid:1286421  QwQ
//by BiliBili@HuangRuibo <-关注喵！
