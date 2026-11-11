#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans,n,a[N],cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;){
		if(a[i]<a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}else if(a[j]<a[i]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}else{
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
