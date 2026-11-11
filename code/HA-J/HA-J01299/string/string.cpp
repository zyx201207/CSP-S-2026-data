#include <bits/stdc++.h>
using namespace std;
long long a[10001];
char c[10001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long n,s=0,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	if(s%2==1){
		for(long long i=1;i<=s/2;i++){
			if(c[i]!=c[i+s/2]) ans++;
		}
	}else{
		for(long long i=1;i<=(s+1)/2-1;i++){
			if(c[i]!=c[i+(s+1)/2]){
				ans++;
			} 
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
