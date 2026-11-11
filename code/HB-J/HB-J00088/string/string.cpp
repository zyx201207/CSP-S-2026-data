#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    int b;
    int num=0;
    string c;
    string n="";
    cin>>a;
for(int i=1;i<=a;i++)
    {
        cin>>b>>c;
        for(int i=1;i<=b;i++)
        {
            n+=c;
        }


        for(int j=0;j<n.size();j++)
        {

            if(n[j]!=n[n.size()-1-j])
            {
                num++;
            }

        }
    }
    cout<<num/4;


    return 0;

}
