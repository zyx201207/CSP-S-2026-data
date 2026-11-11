#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string s1,s2,c1,c2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    //是否在同一车厢
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    string line1=s1.substr(0,2);
    string line2=s2.substr(0,2);
    if(line1!=line2)
    {
        cout<<"1000";
        return 0;
    }
    char sit1=s1[2];
    char sit2=s2[2];
    if(((sit1=='A'||sit1=='B'||sit1=='C')&&(sit2=='A'||sit2=='B'||sit2=='C'))||((sit1=='D'||sit1=='E')&&(sit2=='D'||sit2=='E')))
    {
        //在同一排
        if((sit1=='A'&&sit2=='B')||(sit1=='B'&&sit2=='A')||(sit1=='B'&&sit1=='C')||(sit1=='C'&&sit2=='B')||(sit1=='D'&&sit2=='E')||(sit1=='E'&&sit2=='D'))
        {
            cout<<"1111";
            return 0;
        }
        else
        {
            cout<<"1110";
            return 0;
        }
    }
    else
    {
        //不
        cout<<"1100";
    }
    
    return 0;

    fclose(stdin);
    fclose(stdout);
}