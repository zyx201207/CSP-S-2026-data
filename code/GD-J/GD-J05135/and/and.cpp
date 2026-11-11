#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx=-1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}
	else{
		bool yes=0;
		int eee=0;
		for(int i=1;i<=n;i++)
		{
			if(yes==0&&eee==0&&a[i]==4) eee=4;
			else if(eee==4&&yes==0&&a[i]==4) yes=1;
		}
		if(yes==1) cout<<4;
	    else cout<<0;
	}
	return 0;
}

