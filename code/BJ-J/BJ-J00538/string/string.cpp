#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int leftid=1,rightid=1,leftc=1,rightc=n;
    while(leftc<rightc)
    {
        if(a[leftc]-leftid+1==a[rightc]-rightid+1)
        {
            if(c[leftc]!=c[rightc]) ans+=(long long)(a[leftc]-leftid+1);
            leftc++;
            rightc--;
            leftid=1;
            rightid=1;
        }
        else if(a[leftc]-leftid+1<a[rightc]-rightid+1)
        {
            if(c[leftc]!=c[rightc]) ans+=(long long)(a[leftc]-leftid+1);
            rightid+=a[leftc]-leftid+1;
            leftc++;
            leftid=1;
        }
        else
        {
            if(c[leftc]!=c[rightc]) ans+=(long long)(a[rightc]-rightid+1);
            leftid+=a[rightc]-rightid+1;
            rightc--;
            rightid=1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}