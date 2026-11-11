#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int sum=0;
    for (int i=0; i<n; i++) {
        sum=sum+a[i];
    }
    sort(a,a+n-1);
    for (int i=0; i<sum; i++) {
        for (int k=0; k<n-2; k++) {
            int ans1=0;
            for (int j=k; j<n&&m>0; j++)	{
                if (m>=i-a[j]&&i>=a[j]) {
                    m=m-(i-a[j]);
                    ans1++;
                }
            }
            if (ans1>=ans) {
                //cout << ans1<<endl;
                ans=ans1;
            }
        }
    }
    cout<<ans+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
