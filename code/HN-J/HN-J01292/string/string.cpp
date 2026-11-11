#include<bits/stdc++.h> 
using namespace std;
char m[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long k=1;
	long long cnt=0;//字符总数 
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		cnt+=a;
		for(int j=k;j<=k+a;j++){
			k=a+1;
			m[j]=c;
		}
	} 
	int r=1,l=cnt,ans=0;//三 为修改次数 
	while(r<=l){
		if(m[r]!=m[l]){
			ans++;
			m[r]=m[l];
		}
		r++,l--; 
	} 
	cout<<ans;
	return 0;
} 
