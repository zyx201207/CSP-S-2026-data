#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string S,a;
	long long c[200500],sz=0;
	
	for(int i=0;i<n;i++){
		cin>>c[i]>>a[i];
		sz+=c[i];
	}

	for(int i=0,j=0;i<n;i++){
		for(int j;j<c[i-1]+c[i];j++){
			S[j]=a[i];
		}
	}
	long long ans;
	for(long long i=0,j=sz-1;i<=j;i++,j--){
		if(S[i]!=S[j])ans++;
	}cout<<ans;
	return 0;
}
