#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e5+5;
int n,m,cnt=0;
ll a[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
    	int sum=1;
    	if(m==0) break;
    	int m1=m;
    	for(int j=i-1;j>=0;j--)
    	{
        	if(m1>=(a[i]-a[j])){
        		sum+=1;
        		m1=m1-(a[i]-a[j]);
        	}
       	 	else
       	 	{
       	 		break;
        	}
    	}
        cnt=max(cnt,sum);
    }
    cout<<cnt;
    return 0;
}
