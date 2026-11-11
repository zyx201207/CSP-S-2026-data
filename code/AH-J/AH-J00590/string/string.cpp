#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans=0,l,r,t1,t2;
char b[200010],p,q;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    l=a[1],p=b[1],t1=1;
    r=a[n],q=b[n],t2=n;
    while(t1<t2){
		if(p==q){
			if(l>r){
				l-=r,t2--;
				r=a[t2],q=b[t2];
			}
			else if(l<r){
				r-=l,t1++;
				l=a[t1],p=b[t1];
			}
			else{
				t1++,t2--;
				l=a[t1],p=b[t1];
				r=a[t2],q=b[t2];
			}
		}
		else if(p!=q){
			if(l>r){
				ans+=r;
				l-=r,t2--;
				r=a[t2],q=b[t2];
			}
			else if(l<r){
				ans+=l;
				r-=l,t1++;
				l=a[t1],p=b[t1];
			}
			else{
				ans+=l;
				t1++,t2--;
				l=a[t1],p=b[t1];
				r=a[t2],q=b[t2];
			}
		}
	}
	cout<<ans;
    return 0;
}
