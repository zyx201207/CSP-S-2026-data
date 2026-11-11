#include<bits/stdc++.h>
using namespace std;
char str[5]={'a','b','c','d','f'};
char strm[5]={'a','b','c','d','f'};
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.ont","w",stdont);
    char str1[20],str2[20],str3[20],str4[20];
    cin>>str1>>str2>>str>>str3>>str4>>strm;
    if(str1!=str4)
        cout<<0<<endl;
    else{
        if(str!=strm)
            cout<<0<<endl;
        else
            cout<<1<<endl;
        if(str2==str[4]&&str4==str[3]||str2==str[3]&&str3==str[4])
            cout<<0<<endl;
        else
            cout<<1<<endl;
        if(str2==str3+'1'||str2+'1'==str3)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }

    return 0;
}
