#include<bits/stdc++.h>
using namespace std;
int arr[10]={1,2,3,10,11};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cxa,cxb,zwa,zwb;
    cin>>cxa>>zwa>>cxb>>zwb;
    if(cxa==cxb)
        cout<<1;
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    string tempa="",tempb="";
    tempa+=zwa[0];
    tempa+=zwa[1];
    tempb+=zwb[0];
    tempb+=zwb[1];
    if(tempa==tempb)
        cout<<1;
    else
    {
        cout<<0<<0<<0;
        return 0;
    }
    char sita=zwa[2];
    char sitb=zwb[2];
    if(abs(arr[sita-65]-arr[sitb-65])<=2)
        cout<<1;
    else
    {
        cout<<0<<0;
        return 0;
    }
    if(abs(arr[sita-65]-arr[sitb-65])==1)
        cout<<1;
    else
        cout<<0;
    return 0;
}/*
02 03C 02 03D
*/
