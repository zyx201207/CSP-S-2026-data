#include <iostream>
using namespace std;
const int maxn=2e5+5;
long long len,ans;
int n,l,r;
long long a[maxn];
char c[maxn];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else{
			if(a[l]==a[r]){
				if(c[l]!=c[r])ans+=a[r];
				l++;
				r--;
			}else{
				if(a[l]<a[r]){
					if(c[l]!=c[r]) ans+=a[l];
					a[r]-=a[l];
					l++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
