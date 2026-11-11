#include<bits/stdc++.h>
using namespace std;
string g;
int a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long l=-1,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			l++;
			g[l]=b[i];	
		}
	}
	for(int i=0;i<(l+1)/2;i++){
		if(g[i]!=g[l-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

