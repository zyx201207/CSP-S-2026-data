#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,ans,sum,suma,mid;
char c[200010];
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		suma+=a[i];
		if(suma>=sum/2){
			mid=i;
			break;
		}
	}
	l=1,r=n;
	while(l<mid&&r>mid){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		long long k=min(a[l],a[r]);
		a[l]-=k;
		a[r]-=k;
		if(a[l]==0&&a[r]==0)l++,r--;
		else if(a[l]==0)l++;
		else r--;
		
	}
	if(a[mid-1]!=0&&c[mid-1]!=c[mid])ans+=a[mid-1];
	else if(c[mid+1]!=c[mid]) ans+=a[mid+1];
	cout<<ans;
	return 0;
}
