#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
    int n,m;
    cin>>n>>m;
   
    int a[n+5];
    int sum[m+5];
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i]=a[i]&a[j];
            
        }
    }
    sort(sum,sum+n+1,cmp);

    
    cout<<sum[1];
    return 0;
}
