#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			int k=min(a[i],a[j]);
			ans+=k,a[i]-=k;a[j]-=k;
			if(a[i]==0)i++;
			else j--;
		}else{
			int k=min(a[i],a[j]);
			a[i]-=k;a[j]-=k;
			if(a[i]==0)i++;
			else j--;
		}
	}
	cout<<ans;
}
