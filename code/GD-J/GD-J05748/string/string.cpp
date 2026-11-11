#include<bits/stdc++.h>
using namespace std;
char hwc[1500000000]={};
int main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0,ans=0,a,q;
	char b;
	cin>>n;
	for(long long i=0;i<n;i++){
		q=m;
		cin>>a>>b;
		for(long long j=0;j<a;j++)hwc[j+q]=b;
		m+=a;
	}
	for(long long i=0;i<m/2;i++){
		if(hwc[i]!=hwc[m-m%2-i]&&m-m%2-i<m)ans++;
	}
	cout<<ans;
	return 0;
}
