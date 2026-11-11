#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],tong[30],ma,z=0;
	char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","o",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		tong[b[i]-'a'+1]+=a[i];
		
	}
	for(int i=1;i<=26;i++){
		ma=max(ma,tong[i]);
		if(tong[i]!=0) z++;
	}
	if(z==1){
		cout<<0;
	}else cout<<ma;
	
	return 0;
} 
