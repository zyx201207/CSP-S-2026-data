#include<bits/stdc++.h>
using namespace std;
string a,a1,n,n1;//n/n1=che xiang hao;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string sum="0000";
    cin>>n>>a>>n1>>a1;
    //cout<<n[1]<<n1[1];
    if(n=="01"||n1=="01"||n=="16"||n1=="16")
    {
        return 0;
    }
    if(n[1]==n1[1]&&n[0]==n1[0]){
        sum="1000";
        if(a[0]==a1[0]&&a[1]==a1[1])
        {
            sum="1100";
            if(a[2]!='F'&&a1[2]!='D'&&a1[2]!='F'&&a[2]!='D')
            {
                sum="1110";
                if(a[2]-a1[2]==1) sum="1111";
                if(a1[2]-a[2]==1) sum="1111";
            }
            else if(a[2]=='F'&&a1[2]=='D'||a1[2]=='F'&&a[2]=='D')
            {
                //sum[2]=1;
                //sum[3]=1;
                sum="1111";
            }
        }
    }
cout<<sum;
    return 0;
}
