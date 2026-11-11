#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,sum,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j){
		if(c[i]==c[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				if(a[j]<a[i]){
					a[i]-=a[j];
					j--;
				}else{
					i++,j--;
				}
			}
		}else{
			sum+=min(a[i],a[j]);
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				if(a[j]<a[i]){
					a[i]-=a[j];
					j--;
				}else{
					i++,j--;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
