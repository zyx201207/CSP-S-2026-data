#include<bits/stdc++.h>
using namespace std;
long long n,x[200005],ans,l=1,r;
string a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
	}
	while(1){
		if(x[l]>x[r]){
			if(a[l][0]!=a[r][0]){
				ans+=x[r];
			}
			x[l]-=x[r];
			r--;
		}
		else if(x[l]<x[r]){
			if(a[l][0]!=a[r][0]){
				ans+=x[l];
			}
			x[r]-=x[l];
			l++;
		}
		else {
			if(a[l][0]!=a[r][0]){
				ans+=x[l];
			}
			l++;
			r--;
		}
		if(l==r)break;
	}
	cout<<ans;
	return 0;
} 
