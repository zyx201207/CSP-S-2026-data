#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e6+7;
const ull LLMX=0x3f3f3f3f3f3f3f3full;
int n,q[N],h[N],f[N];
ull d,a[N];
bool cd[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		f[0]=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			long long all;
			cin>>all;
			a[i]=all+LLMX;
		}
		ull r=0;
		q[n-1]=-1,h[0]=-1,n-=3;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]+(a[i+1]-a[i-1]<=d&&a[i]-a[i-1]<=d&&a[i+2]-a[i-1]>d);
			if(a[i+2]-a[i+1]>d) f[i]=0;
			for(int j=1;j<=i;j++)
				if(f[i]-f[j-1]==1)
					r++;
		}
		cout<<r<<endl;
	}
	return 0;
}
