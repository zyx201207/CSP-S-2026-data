#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long x;
char y;
string z;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(long long i=1;i<=n;i++){
	cin>>x;
	cin>>y;
	for(long long j=1;j<=x;j++){
		z+=y;
	}
}
	int l=0;
	int r=z.size();
if(r%2==0){
	for(int i=1;i<=r/2;i++){
		if(z[l]!=z[r]){
			ans++;
		}
	}
}else{
	for(int i=1;i<=(r-1)/2;i++){
	    if(z[l]!=z[r]){
	    	ans++;
		}	
	}
}

	cout<<ans;
	return 0;
}
