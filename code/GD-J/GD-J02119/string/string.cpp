#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<=j){
		if(b[i]==b[j]){
			if(a[i]>=a[j]) a[i]-=a[j],j--;
			else a[j]-=a[i],i++;
		}
		else{
			if(a[i]>=a[j]) a[i]-=a[j],ans+=a[j],j--;
			else a[j]-=a[i],ans+=a[i],i++;
		}
	}
	cout<<ans;
	return 0;
} 
