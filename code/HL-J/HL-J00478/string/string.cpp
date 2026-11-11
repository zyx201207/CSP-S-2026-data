#include<bits/stdc++.h>
using namespace std;
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
long long n,s=0,sum_=0;
char ch;
long long ar[500000][2];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i][0]>>ch;
        ar[i][1]=int(ch);
        s+=ar[i][0];
    }
    s=(s+1)/2;
    long long l=0,r=s-1,a=0,f=n-1;
    while(l<=s)
    {
        long long su=ar[a][0];
        long long fs=ar[f][0];
        if(a>=f)
        {
            break;
        }
        if(ar[a][1]==ar[f][1])
        {
            l+=min(su,fs);
            ar[a][0]-=min(su,fs);
            ar[f][0]-=min(su,fs);
            if(ar[a][0]==0)a++;
            if(ar[f][0]==0)f--;
            if(a==f)break;
        }
        else
        {
            if(ar[a][0]<ar[f][0])
            {
                ar[f][0]-=ar[a][0];
                sum_+=ar[a][0];
                l+=ar[a][0];
                a++;
            }
            else if(ar[a][0]>ar[f][0])
            {
                ar[a][0]-=ar[f][0];
                sum_+=ar[f][0];
                l+=ar[f][0];
                f--;
            }
            else
            {
                sum_+=ar[f][0];
                l+=ar[a][0];
                a++;
                f--;
            }
        }
    }
    cout<<sum_;
    return 0;
}
