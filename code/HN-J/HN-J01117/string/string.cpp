#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long i=1,j=n,t;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
		}
		t=a[i];
		a[i]-=min(t,a[j]);
		a[j]-=min(t,a[j]);
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
//		cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}

