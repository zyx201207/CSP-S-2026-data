#include <bits/stdc++.h>
using namespace std;
string cnts="";
long long nshu,zc;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>nshu;
    for(int i=1;i<=nshu;i++)
    {
        int gshu;
        string zm="";
        cin>>gshu>>zm;
        for(int j=1;j<=gshu;j++)
        {
            cnts=cnts+zm;
        }
    }
    long long cd=cnts.size();
    long long l=0,r=cd-1,gg=0;
    while(l<r)
    {
        if(cnts[l]!=cnts[r])
        {
            gg++;
        }
        l++;
        r--;
    }
    cout<<gg;
    return 0;
}

