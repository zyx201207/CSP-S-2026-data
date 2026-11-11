#include<bits/stdc++.h>
using namespace std;
int n;
long long s,ans;
string sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=s;j<a+s;j++){
			sum[j]=c;
		}s=s+a;
	}
	for(int i=0;i<=s/2;i++){
		if(sum[i]!=sum[s-1-i]){
			ans++;
		}
	}cout<<ans;
	

	return 0;
	
}
