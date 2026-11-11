#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]<a[r]) a[r]-=a[l],l++;
		else if(a[l]>a[r]) a[l]-=a[r],r--;
		else l++,r--;
	}
	cout<<ans;
	return 0;
}
