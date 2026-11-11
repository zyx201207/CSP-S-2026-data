#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2,arr[10],sum1,sum2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        arr[0] = s1[0];
        arr[1] = s1[1];
        arr[2] = s2[0];
        arr[3] = s2[1];
        if(arr[0]!=arr[2])
        {
            cout<<"1000";
            return 0;
        }
        else
        {
            if(arr[1]!=arr[3])
            {
                cout<<"1000";
                return 0;
            }
            arr[4] = s1[2];
            arr[5] = s2[2];
            if(arr[4]=="A"||arr[4]=="B"||arr[4]=="C")
            {
                sum1 = "abc";
            }
            else{
                sum1 = "df";
            }
            if(arr[5]=="A"||arr[5]=="B"||arr[5]=="C")
            {
                sum2 = "abc";
            }
            else
            {
                sum2 = "df";
            }
            if(sum1!=sum2)
            {
                cout<<"1100";
                return 0;
            }
            else
            {
                if(sum1=="df")
                {
                    cout<<"1111";
                    return 0;
                }
                else{
                    if(arr[4]=="B" || arr[5]=="B")
                    {
                        cout<<"1111";
                        return 0;
                    }
                    else{
                        cout<<"1110";
                        return 0;
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
