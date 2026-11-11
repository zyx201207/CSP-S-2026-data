#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1>>s1>>c2>>s2;
    if (c1==c2){
        cout<<"1";
        bool flag=1;
        for (unsigned int i=0;i<s1.size()-1;i++)
        {
            if (s1[i]!=s2[i]) {
                    flag=0;
            }
        }
        if (flag) {
                cout<<1;
                if ((s1[2]<='C' && s2[2]<='C' )|| (s1[2]>='D' && s2[2]>='D' ))
                {
                    
                    if (s1[2]-s2[2]==1 || s1[2]-s2[2]==-1) {
                        cout<<"11";
                    }
                    else
                    {
                        cout<<"10";
                    }
                }
                else cout<<"00";
        }
        else cout<<"000";
        
	}
	else cout<<"0000";
  return 0;
}