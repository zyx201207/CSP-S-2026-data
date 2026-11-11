#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000100],c=1,d,cnt;
string b[10100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m+=a[i];
	}
	d=n;
	for(int i=1;;i++){
		if(c==d){
			cout<<cnt;
			return 0;
		}
		if(a[c]>=a[d]){
			if(b[c]!=b[d]){
				cnt+=a[d];
				a[c]=a[c]-a[d];
				a[d]=0;
				d--;
				continue;
			}else{
				a[c]=a[c]-a[d];
				a[d]=0;
				d--;
				continue;
			}
		}
		if(a[c]<a[d]){
			if(b[c]!=b[d]){
				cnt+=a[c];
				a[d]=a[d]-a[c];
				a[c]=0;
				c++;
			}else{
				a[d]=a[d]-a[c];
				a[c]=0;
				c++;
			}
		}
	}
	return 0;
}

