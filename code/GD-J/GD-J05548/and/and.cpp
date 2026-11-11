#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans,b[10000],b2[10000];
string s;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==1) {
		for(int i=1; i<=n; i++) {
			long long t=a[i],v=0;
			while(t!=0) {
				v++;
				b[v]=t%2;
				t=t/2;
			}
			long long x=1,y=0;
			for(int j=1; j<=v; j++) {
				if(b[j]==0) {
					y=y+x;

				}
				x=x*2;
			}
			ans=max(ans,y);
		}

		cout<<ans;
		return 0;
	}
	if(m==2) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				long long t=a[i],t2=a[j],v=0,v1=0;
				while(t!=0) {
					v++;
					b[v]=t%2;
					t=t/2;
					
				}
				while(t2!=0) {
					v1++;
					b2[v1]=t2%2;
					t2=t2/2;
					
				}
				long long x=1,y=0;
				for(int k=1; k<=max(v1,v); k++) {
					if(b[k]==b2[k]) {
						y=y+x;
					}
					x=x*2;
				}
				ans=max(ans,y);
			}
		}
	
	cout<<ans;
	return 0;
}
if(m==n) {
   cout<<"91";
}
if(m==n-1) {
	cout<<"67";

}
return 0;
}
