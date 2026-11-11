#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	long long n,le,ans=0;
	string sum;
	cin>>n;
		int a;
		string c;
	for(long long i=0;i<n;i++){
	
		cin>>a>>c;
		while(a>0){
			 sum+=c;
			 le++;
			 a--;
		}
	}
		for(long long j=0;j<le;j++){
			if(sum[j]!=sum[le+1-j]){
				ans++;
			}
		}
	
	cout<<ans;
	return 0;
} 
