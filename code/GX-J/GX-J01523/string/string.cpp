#ifndef STRING_CPP_INCLUDED
#define STRING_CPP_INCLUDED



#endif // STRING_CPP_INCLUDED
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
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
    }
    cout<<w;
    return 0;
}
