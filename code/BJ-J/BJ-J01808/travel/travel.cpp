#include<iostream>
#include<algorithm>

using namespace std;
int main(){
   freopen("travel.in",'r',stdin)
   freopen("travel.out",'w',stdout)
    string c1, c2, c3, c4, c5, c6;
    cin>>c1>>c2>>c3>>c4>>c5>>c6;
    if(c1!=c4)
        cout<<"0000";
        break;
    else
        cout<<"1";

    if(c2=c5)
        cout<<"1";
    else
        cout<<"0";

    if(('A'<=c3<='C'&&'A'<=c6<='C')||('D<=c3<='E'&&'D'<=c6<='E))
        cout<<"1";
    else
        cout<<"0";

    if((c3+1-'0'=c6||c3-1-'0'=c6)&&(c3!='C||c3!='D'))
        cout<<"1";
    else
        cout<<"0";

    return 0;
}
