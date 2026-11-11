#include "iostream"
#include "cmath"
using namespace std;
long long n,a[200005],num;
char c[200005];
long long ans,p,q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	long long ss=0,tt=n-1;
	while(ss<=n/2&&tt>=n/2){
	//cout<<num<<'\n';
		if(c[tt]!=c[ss]&&a[ss]&&a[tt]){
			ans+=min(a[ss],a[tt]);
			num-=min(a[ss],a[tt]);
			p=a[ss]-a[tt];
			q=a[tt]-a[ss];
			if(p<=0){
				a[tt]-=a[ss];
				a[ss]=0;
				ss++;
			}
			if(q<=0){
				a[ss]-=a[tt];
				a[tt]=0;
				tt--;
			}
		}
		else if(c[tt]==c[ss]&&a[ss]&&a[tt]){
			num-=min(a[ss],a[tt]);
			p=a[ss]-a[tt];
			q=a[tt]-a[ss];
			if(p<=0){
				a[tt]-=a[ss];
				a[ss]=0;
				ss++;
			}
			if(q<=0){
				a[ss]-=a[tt];
				a[tt]=0;
				tt--;
			}
		}	
	}
	cout<<ans;
	return 0;
}
