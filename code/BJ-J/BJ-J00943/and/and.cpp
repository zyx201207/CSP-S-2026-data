#include <bits/stdc++.h>
using namespace std;

long long n,m,max_yu=-1e9,i2,j2,i,j;
const long long abcdefhjgijkrgo=2*1e5+10;
long long num[abcdefhjgijkrgo];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> num[i];
    }
    if(m==1)
    {
        sort(num+1,num+1+n);
        cout << num[n];
        return 0;
    }
    long long totle = m-1;
    while(totle--)
    {
        max_yu=0;

        for(i = 1;i+1<=n;i++)
        {

            for(j = i+1;j<=n;j++)
            {

                long long yu = num[i]&num[j];

                if(yu>max_yu)
                {
                    max_yu = yu;
                    i2=i;
                    j2=j;
                }




            }
        }
        num[i2]=max_yu;
        num[j2]=0;
    }
    cout <<max_yu;
}

