#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[1000000],ans=0,i=1,j;
	char m[1000000];
	cin>>n;
	j=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>m[i];
	while(i<j){
		if(m[i]!=m[j]){
			ans+=min(a[i],a[j]);
		}
		if(a[i]<a[j]){
			a[j]=a[j]-a[i];
			i++;
		}
		else if(a[i]>a[j]){
			a[i]=a[i]-a[j];
			j--;
		}
		else{
			i++;j--;
		}
	}
	cout<<ans;
	return 0;
}
