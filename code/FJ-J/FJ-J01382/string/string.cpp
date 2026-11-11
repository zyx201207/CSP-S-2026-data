#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=0;
//long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long> a(n+5,0);
	vector<char> c(n+5);
	for(long long i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}

	
	long long r=1,l=n;
	while(r<l){
		if(r>n||l<0)break;
		if(a[r]==a[l]&&c[r]==c[l])
		{
			a[r]=a[l]=0;r++;l--;
		}
		else
		{
			if(a[r]<a[l])
			{
				if(c[r]!=c[l])ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r++;
			}
			else if(a[r]>a[l])
			{
				if(c[r]!=c[l])ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l--;
			}else{
				ans+=a[r];
				a[r]=a[l]=0;
				r++;l--;
			}
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
