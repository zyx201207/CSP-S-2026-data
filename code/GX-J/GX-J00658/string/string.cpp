#include<bits/stdc++.h>
using namespace std;
long long num_Q[100000000];
char word_Q[20000];
long long time_Q;
long long a;
int main()
{   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>time_Q;
    for(int i=0;i<time_Q;i++)
    {
        cin>>num_Q[i]>>word_Q[i];
    }

    for(int i=0;i<time_Q/2;i++)
    {
        if (word_Q[i]!=word_Q[time_Q/2])
        {
            a+=num_Q[i];
        }

    }
    cout<<a;
    return 0;
}
