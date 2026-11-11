#include<bits/stdc++.h>
using namespace std;
long long n,b;
long long ant,cnt;
string a[10000001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        long long ans;
        char c;
        cin>>ans>>c;

        for(long long j=ant;j<=ant+ans;j++)
        {
            a[i][j]=c;
        }
        ant+=ans;
    }
    for(long long i=0;i<=ant;i++)
    {
        if(a[b][i]!=a[n-b][ant-i] && i<ant-i-1 && b<=n-b)
        {
            cnt++;
            if(a[i]!=a[ant-i])
            {

                cout<<1;
            }
            cout<<a[i]<<" "<<a[ant-i];
        }
        if(i>=ant-i)
        {

            b++;
        }
    }
    cout<<cnt;

    return 0;
}
