#include<bits/stdc++.h>
using namespace std;
long long n,m,in,l,r,mid,ans;
long long a[500005],q[500005],o;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;++i){
        o+=a[i];q[i]+=o;
    }
    for(int i=0;i<n;++i){
        l=0;r=i;mid=(l+r)/2;
        while(l<r){
            if((a[i]*(i-mid+1))-q[i]+q[mid-1]==m) break;
            if((a[i]*(i-mid+1))-q[i]+q[mid-1]>m) l=mid+1;
            else r=mid;mid=(l+r)/2;
        }
        ans=max(ans,i-mid+1);
    }
    cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
