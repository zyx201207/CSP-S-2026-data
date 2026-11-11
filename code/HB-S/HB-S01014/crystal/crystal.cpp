#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	long long a[n];
	if(m==0)
    {
        cout<<'1'<<endl;
        return 0;
    }
	for(long long i=0;i<n;i++)
		cin>>a[i];
    long int k=abs(a[0]-a[1]);
    for(int i=0;i<n;i++)
        if(i*(i+1)*k/2>m)
        {
            cout<<i<<endl;
            return 0;
        }
    cout<<n<<endl;
    return 0;
}
