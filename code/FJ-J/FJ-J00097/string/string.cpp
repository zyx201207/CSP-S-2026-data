#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[200005];
long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}
		else{
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
}
