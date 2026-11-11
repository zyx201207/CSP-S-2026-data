#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],ans;
char b[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<j){
		int c=min(a[i],a[j]);
		if(b[i]!=b[j]) ans+=c;
		a[i]-=c;
		a[j]-=c;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}

