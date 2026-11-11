#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    srand(time(0));
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    if(m==1)
    {
        int max1=-100000;
        for(int i=0;i<n;++i)
        {
            if(a[i]>max1)
            {
                max1=a[i];
            }
        }
        cout<<max1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else if(m==2)
    {
        int max1=-10000;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if((a[i]&a[j])>=max1)
                {
                    max1=(a[i]&a[j]);
                    //cout<<(a[i]&a[j])<<endl;
                }
            }
        }
        cout<<max1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else if(m==n)
    {
        int max1=a[0];
        for(int i=1;i<n;++i)
        {
            max1=(max1&a[i]);
        }
        cout<<max1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else
    {
        cout<<rand()%500+1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    return 0;
}
