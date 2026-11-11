//贵州省六盘水市第三中学 刘宇帆 GJ-J00586 
#include<bits/stdc++.h>
using namespace std;
int n,s,t,cnt;
char b[300005];
long long sum,a[300005];
string as,as2;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			as+=b[i];
		}
	}	
	for(int i=as.size()-1;i>=0;i--){
		as2+=as[i];
	}
	
	if(as.size()%2==1){
		s=as.size()/2+1;
	}else {
		s=as.size()/2;
	}
	for(int i=s;i<as.size();i++){
		t++;
		if(as[i]!=as[i-t-t]){
			cnt++;
		}
	}	
	cout<<cnt;
	return 0;
} 
