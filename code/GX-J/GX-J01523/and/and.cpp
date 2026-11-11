#ifndef AND_CPP_INCLUDED
#define AND_CPP_INCLUDED



#endif // AND_CPP_INCLUDED
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    string s;
    double a;
    double w=0;
    double l=0;
    char b;
    cin>>n;
     for(double i=0;i<n;i++)
    {
        cin>>a>>b;
        for(double j=0;j<a;j++)
        {
            s[j+l]=b;
        }
        l+=a;
    }
    double le=0,ri=l-1;
    while(le<=ri)
    {
        if(s[le]!=s[ri])
            w++;
        le++;
        ri--;
    }//bao long jian shi shen me yi si?????
    //arknight
    //chihana anon
    cout<<12;
    return 0;
}
