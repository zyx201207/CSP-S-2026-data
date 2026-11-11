#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],p,t;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int b;
		char h;
		cin>>b>>h;
		if(h!=c[p]){
			c[++p]=h;
		}a[p]+=b;
	}for(int i=1;i<=p/2;++i){
		if(c[i]!=c[p-i+1]&&(a[i]!=0&&a[p-i+1]!=0)){
			if(abs(a[i]-a[p-i+1])>0){
				t+=min(a[i],a[p-i+1]);
				if(a[i]>a[p-i+1]){
					a[i]-=a[p-i+1];
					a[p-i+1]=0;
				}else{
					a[p-i+1]-=a[i];
					a[i]=0;
				}
			}else t+=a[i];
		}
	}cout<<t;
	return 0;
}
//44AC
