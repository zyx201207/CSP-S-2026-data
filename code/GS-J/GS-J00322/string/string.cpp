#include<bits/stdc++.h>
using namespace std;
struct{
	long long a;
	string c;
}a[200005];
long long n,ans,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	l=1,r=n;
	while(l<r){
		int minn=min(a[l].a,a[r].a);
		if(a[l].c!=a[r].c){
			ans+=minn;
		}
		a[l].a-=minn;
		a[r].a-=minn;
		if(a[l].a==0){
			l++;
		}
		if(a[r].a==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
