#include<bits/stdc++.h>
using namespace std;
long long n,ans,s,si=1,sj,v[200005];
char a[200005];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	sj=n;
	for(long long i=1;i<=n;i++) {
		cin>>v[i]>>a[i];
		s+=v[i];
	}
	for(long long i=1,j=s;i<j;) {
		i=i+min(v[si],v[sj]);
		j=j-min(v[si],v[sj]);
		if(a[si]!=a[sj]) {
			ans+=min(v[si],v[sj]);
		}
		if(v[si]<v[sj]) {
			v[sj]-=v[si];
			si++;
		}
		else if(v[si]>v[sj]) {
			v[si]-=v[sj];
			sj--;
		}
		else {
			si++;
			sj--;
		}
	}
	cout<<ans;
	
	return 0;
}
