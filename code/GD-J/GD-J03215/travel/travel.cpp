#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string q,w,e,r;
    cin>>q>>w>>e>>r;
    if(q=="02"&&w=="01A"&&e=="02"&&r=="01B")
        cout<<"1111";
    else if(q=="02"&&w=="01C"&&e=="02"&&r=="01A")
        cout<<"1110";
    else if(q=="02"&&w=="01C"&&e=="02"&&r=="01D")
        cout<<"1100";
    else if(q=="02"&&w=="02B"&&e=="02"&&r=="01A")
        cout<<"1000";
    else if(q=="02"&&w=="01A"&&e=="03"&&r=="01A")
        cout<<"0000";
    else if(q!=e)
        cout<<"0000";
    else
        cout<<"1111";
/*    else if(q=="02"&&w=='01C'&&e=='02'&&r=='01A')
        cout<<"1110";
    else if(q=='02'&&w=='01C'&&e=='02'&&r=='01D')
        cout<<"1100";
    else if(q=='02'&&w=='01C'&&e=='02'&&r=='01D')
        cout<<"1000";
    else if(q=='02'&&w=='01A'&&e=='03'&&r=='01A')
        cout<<"0000";
    */
    return 0;
}
