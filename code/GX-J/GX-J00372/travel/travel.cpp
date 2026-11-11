//travel.cpp                                                                    
#include<iostream>
using namespace std;

int main()
{
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    char c1,s1,b1,d1,c2,s2,b2,d2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        else
        {
             cout<<"0";
        }
        else if(c1==c2&&b1==b2)
        {
             cout<<"1";
             else
             {
				 cout<<"0";
			 }
             else if(c1==c2&&b1==b2&&d1==d2)
             {
	         cout<<"1";
                 else
                 {
                     cout<<"0";
                 }
                 else if(c1==c2&&b1==b2&&d1==d2&&s1==s2)
                 {
                     cout<<"1";
                     else
                     {
                          cout<<"0";
                     }
                 }
             }
    }
    return 0;
}
