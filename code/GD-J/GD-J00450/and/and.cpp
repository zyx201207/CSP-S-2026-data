#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],ans,jl,jg,bj[200010],ans2,bj2[2000010],jl2,jg2;
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n-1];
	jl=n-1;
	bj[n-1]=1;
	jg++;
	// cout<<a[n-1]<<" ";
	for (int i=n-1;i>=1;i--){
		if (jg==m){
			break;
		}
		if ((a[jl]&a[i])==0 || bj[i]==1){
			continue;
		}
		bj[i]=1;
		ans&=a[i];
		jg++;
		jl=i;
		// cout<<a[i]<<" ";
	}
	if (jg<m){
		for (int i=n;i>=1;i--){
			if (jg==m){
				break;
			}
			if (!bj[i]){
				ans&=a[i];
				// cout<<a[i]<<" ";
				jg++;
			}
		}
	}
	ans2=a[n];
	jl2=n;
	bj2[n]=1;
	jg2++;
	// cout<<a[n-1]<<" ";
	for (int i=n-1;i>=1;i--){
		if (jg2==m){
			break;
		}
		if ((a[jl]&a[i])==0 || bj2[i]==1){
			continue;
		}
		bj2[i]=1;
		ans2&=a[i];
		jg2++;
		jl2=i;
		// cout<<a[i]<<" ";
	}
	if (jg2<m){
		for (int i=n;i>=1;i--){
			if (jg2==m){
				break;
			}
			if (!bj2[i]){
				ans2&=a[i];
				// cout<<a[i]<<" ";
				jg2++;
			}
		}
	}

	// cout<<"\n"<<jg<<"\n";
	cout<<max(ans,ans2);	
	return 0;
}