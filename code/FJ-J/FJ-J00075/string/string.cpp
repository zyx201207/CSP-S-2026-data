#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1;
	while(i<n){
		int s=min(a[i],a[n]);
		if(b[i]!=b[n]){
			ans+=s;
		}
		a[i]-=s,a[n]-=s;
		if(a[i]==0){
			i++;
		}
		if(a[n]==0){
			n--;
		}
	}
	cout<<ans;
	return 0;
}
