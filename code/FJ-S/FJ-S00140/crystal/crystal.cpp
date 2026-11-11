#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	s[0]=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		long long mid=(l+r)/2;
		//cout<<"Round "<<i<<":\n";
		while(l<r){
			mid=(l+r)/2;
			long long bas=(i-mid+1)*a[i];
			//cout<<"l="<<l<<",r="<<r<<",try mid="<<mid<<endl;
			//cout<<"bas="<<bas<<",s[i]-s[mid-1]="<<s[i]-s[mid-1]<<endl;
			//cout<<"now="<<bas-(s[i]-s[mid-1])<<endl;
			//if(bas-(s[i]-s[mid-1])>m) cout<<"unok\n\n";
			//else cout<<"ok\n\n";
			if(m<bas-(s[i]-s[mid-1])){
				l=mid+1;
			}
			else r=mid;
		}
		//cout<<"final:"<<r<<"\n";
		//cout<<"--------------------------------------------------------------------------------\n";
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
