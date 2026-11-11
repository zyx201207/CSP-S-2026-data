#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int l=1;l<=n;l++) cin>>a[l]>>c[l];
	int i=1,j=n;
	while(i<j){
		int x=min(a[i],a[j]);
		if(c[i]!=c[j]) ans+=x;
		a[i]-=x;
		a[j]-=x;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}

