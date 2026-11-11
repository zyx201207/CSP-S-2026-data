#include<bits/stdc++.h>
using namespace std;
char c[20005];
string s,b,f;
int n,a[20005],cnt=0,sum=0,t,k=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[cnt]+=c[i];
			cnt++;
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(sum%2==0){
		t=(sum-1)/2;
	}else{
		t=(sum-1)/2-1;
	}
	for(int i=0;i<=t;i++){
		f[i]=s[i];
	}
	if(sum%2==0){
		for(int i=sum-1;i>=t;i--){
			b[cnt]=s[i];
			cnt++;
		}
	}else{
		for(int i=sum-1;i>=t+1;i--){
			b[cnt]=s[i];
			cnt++;
		}
	}
	for(int i=0;i<=t;i++){
		if(b[i]!=f[i]){
			k++;
		}
	}
	cout<<k;
	return 0;
}
