#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ans=0;
	cin>>n;
	int a[n],len=0,part[n+1];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		part[i+1]=len; 
	}
	int t=0;
	char real[len+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			real[t]=c[i];
			t++;
		}
	}
	real[len+1] = '\0';
//	cout<<real;
	for(int i=0;i<=len-1;i++){
//		cout<<real[len-1-i]<<" ";
		if(real[i]!=real[len-1-i]){
			ans++;
//			cout<<ans<<" ";
		}
	}
	cout<<ans/2;
}


