//GZ-J00657 陈恩源 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
long long n;
struct qwe{
	long long a;
	char b;
}a[200005],b[200005];
long long x=0,x1=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b;
	}
	for(int i=0;i<n;i++){
		b[i].a=a[n-i-1].a;
		b[i].b=a[n-i-1].b;
	}
	while(x<=n/2-1||x1<=n/2-1){
		if(a[x].b!=b[x1].b){
			ans++;
		}
		a[x].a--;
		b[x1].a--;
		if(a[x].a==0){
			x++;
		}
		if(b[x1].a==0){
			x1++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
