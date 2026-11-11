#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,in[200005],ans[200005],out;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<m+i;j++){
			ans[i]=in[i]&in[j];
		}
	}sort(ans,ans+n);
	for(int i=0;i<n;i++){
		out=max(out,ans[i]);
	}cout<<out;
	return 0;
}