#include <bits/stdc++.h>
using namespace std;
int n;
long long a[20005],mn[20005],s,m;
char c[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
		mn[i]=mn[i-1]+a[i];
	}
	long long i=1,j=m;
	int k=1,q=n;
	while(k<q){
		if(i<=mn[k] && j>mn[q-1]){
			long long t=mn[k]-i+1;
			long long v=j-mn[q-1];
			if(c[k]!=c[q]) s+=min(t,v);
			i+=min(t,v);
			j-=min(t,v);	
		}
		if(i>mn[k]) k++;
		if(j<=mn[q-1]) q--;
	}
	if(n%2!=0){
		k=n%2+1;
		s+=min(mn[k]-i+1,j-mn[k]);
	}
	cout<<s;
	return 0;
}
