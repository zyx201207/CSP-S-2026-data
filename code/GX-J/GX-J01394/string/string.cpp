#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long  n;
    string s;
    cin>>n;
    char c;
    long long m;
    long long cnt=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>m>>c;
        for(long long j=1;j<=m;j++)
        {

          s+=c;

        }

    }
    long long  l=1,r=s.size();
    for(long long i=l;i<r;i++)
    {
        for(long long j=r;j>l; j--)
        {
            bool flag=false;
            if(s[i]==s[j])
            {

                flag=true;
            }
            else{
                s[j]=s[i];
                cnt++;
            }

        }
    }
    cout<<cnt-1<<endl;
    fclose(stdin);
    fclose(stdout);
  return 0;

}
