#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100000]={},ans=0;
	char c[100000]={};
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
