#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	string zf="";
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		cnt+=a;
		while(a--){
			zf+=c;
		}
	} 
	long long ans=0;
	for(int i=0;i<=cnt/2;i++){
		if(zf[i]!=zf[cnt-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
