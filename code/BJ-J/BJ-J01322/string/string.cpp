#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int top=1,endd=n;
	while(top<endd){
		int mmin=min(a[top],a[endd]);
		if(c[top]!=c[endd]){
			ans+=mmin;
		}
		a[top]-=mmin;
		a[endd]-=mmin;
		if(a[top]==0) top++;
		if(a[endd]==0) endd--;
	}
	cout<<ans;
	return 0;
}
