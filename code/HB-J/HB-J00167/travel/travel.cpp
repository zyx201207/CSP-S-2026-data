#include<bits/stdc++.h>
using namespace std;
char x[10];
char y[10];
char z[10];
char a[10];
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    for(int i = 1;i<=2;i++)
        cin>>x[i];
    for(int i = 1;i<=3;i++)
        cin>>y[i];
    for(int i = 1;i<=2;i++)
        cin>>z[i];
    for(int i = 1;i<=3;i++)
        cin>>a[i];
    if(x[1] == z[1] && x[2] == z[2])
    {
        cout<<"1";
        if(y[1] == a[1] && y[2] == a[2])
        {
            cout<<"1";
            if(y[3] == 'A' || y[3] == 'B' || y[3] == 'C')
            {
                if(a[3] == 'A' || a[3] == 'B' || a[3] == 'C')
                {
                    cout<<"1";
                    {
                        if(y[3] == 'A' && a[3] == 'B')
                        {
                            cout<<"1";
                            return 0;
                        }
                        else if(y[3] == 'B' && a[3] == 'A')
                        {
                            cout<<"1";
                            return 0;
                        }
                        else if(y[3] == 'B' && a[3] == 'C')
                        {
                            cout<<"1";
                            return 0;
                        }
                        else if(y[3] == 'C' && a[3] == 'B')
                        {
                            cout<<"1";
                            return 0;
                        }
                        cout<<"0";
                        return 0;
                    }
                }
                cout<<"00";
                return 0;
            }
            if(y[3] == 'F' || y[3] == 'D' )
            {
                if(a[3] == 'F' || a[3] == 'D' )
                {
                    cout<<"1";
                    return 0;
                }
                cout<<"00";
                return 0;
            }
            cout<<"00";
            return 0;
        }
        cout<<"000";
        return 0;
    }
   return 0;
}
