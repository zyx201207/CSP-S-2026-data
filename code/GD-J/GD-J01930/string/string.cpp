#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum=0;
long long s[200020];
char a[200020];
long long check(){
	long long ans=0;
	for(long long i=0;i<=(sum-1)/2;i++){
		char t,v;
		for(long long j=1;j<=n;j++){
			if(i<=s[j]&&i>=s[j-1]){
				t=a[j];
			}
			if(sum-1-i<=s[j]&&sum-i-1>=s[j-1]){
				v=a[j];
			}
		}
		if(t!=v){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		s[i]=sum+x-1;
		a[i]=y;
		
		sum+=x;
	}
	cout<<check();
	return 0;	
}

