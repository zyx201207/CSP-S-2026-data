#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans,num[200005],l,r;
int sum;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        num[i]+=a[i]+num[i-1];
    }
    int i=1,j=n-1;
    r=num[n];
    while(l<=num[n]/2){
        if(num[i]-l>r-num[j])
        {
            l+=r-num[j];
            if(c[i]!=c[j])
            {
                ans+=r-num[j];
            }
            r=num[j];
            j--;
        }
        else if(num[i]-l==r-num[j]){
            if(c[i]!=c[j])
            {
                ans+=num[i]-l;
            }
            l=num[i],r=num[j];
            i++,j--;
        }
        else{
            r-=num[i]-l;
            if(c[i]!=c[j]){
                ans+=num[i]-l;
            }
            l=num[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}