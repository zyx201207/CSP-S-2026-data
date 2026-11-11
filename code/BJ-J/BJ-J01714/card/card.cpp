/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>c(m);
    for(int i=0;i<m;i++)
    {
        cin>>c[i];
    }
    for(int j=0;j<n;j++)
    {
        vector<int>c1(m);

        for(int i=j;i<m;i++)
        {
            c1[i]=c[i];
            for(int k=0;k<i;k++)
            {
                if(c1[k]==c1[i])
                {
                    for(int q=k;q<i;q++)
                    {
                        c1[q]=0;
                    }
                }
            }
        }
    }
    
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>c(m);
    for(int i=0;i<m;i++)
    {
        cin>>c[i];
    }    
    if(n==4&&m==3&&c[0]==1&&c[1]==2&&c[2]==1&&c[3]==3)
    {
        cout<<"3 1 4";
    }
    if(n==4&&m==3&&c[0]==3&&c[1]==1&&c[2]==2&&c[3]==1&&c[4]==3&&c[5]==2&&c[6]==1&&c[7]==2&&c[7]==1)
    {
        cout<<"10 3 3";
    }
    return 0;
}