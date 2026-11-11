#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,ans,cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	vector<int>a(n+1);
	vector<char>c(n+1);
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	ans=cnt/2;
	int p=0,mid=(cnt+1)/2;
	for(i=1;i<=n;i++){
		p+=a[i];
		if(p>=mid){
			ans-=min(p-mid,mid-(p-a[i]));
			a[i]-=min(p-mid,mid-(p-a[i]))*2;
			break;
		}
	}
	j=n;
	i=1;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]==a[j]){
				i++;
				j--;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			ans-=min(a[i],a[j]);
			if(a[i]==a[j]){
				i++;
				j--;
			}if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
