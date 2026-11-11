#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005],m;
char b[200005];
string k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m+=a[i];
		for(long long j=1;j<=a[i];j++){
			k+=b[i];
		}
	} 
	int x=n;
	if(a[1]!=a[x]&&b[1]!=b[x]&&a[1]<10000000){
			int j=m-1;
	        for(long long i=0;i<m/2;i++){
	            if(k[i]!=k[j]){
			    ans++;
		    	j--;
            	}
	     	}
	}
	else{
	    for(long long i=1;i<=n/2;i++){
		if(a[i]==a[x]&&b[i]!=b[x])ans+=a[i]; 
		else if(a[i]!=a[x]&&b[i]!=b[x])ans+=max(a[i],a[x]);
		x--;
	}}
	cout<<ans;
	return 0;
}
