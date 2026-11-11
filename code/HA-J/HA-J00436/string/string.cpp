#include<bits/stdc++.h>
using namespace std;
#define int long long
const int A=2e5+5;
int n,b[A],sum,num,l,r;
char a[A];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		cin>>a[i];
	}
	l=1,r=n;
	while(1)
	{
		int maxn=max(b[l],b[r]),minn=min(b[l],b[r]);
		if(n%2==1){
			if(l==r){
				break;
			}
		}
		else{
			if(l==r-1)
			{
				if(a[l]!=a[r]){
					num+=minn;
				}
				break;
			}
		}
		if(a[l]!=a[r]){
			num+=minn;
		}
		if(b[l]>b[r]){
			b[l]=b[l]-b[r];
			r-=1;
		}
		else if(b[l]<b[r]){
			b[r]=b[r]-b[l];
			l+=1;
		}
		else{
			r-=1,l+=1;
		}
	}
	cout<<num;
	return 0;
}
