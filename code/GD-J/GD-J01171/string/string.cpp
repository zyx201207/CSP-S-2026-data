#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,a[N],r,rs,sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	r=n;
	for(int i=1;i<r;i++){
		int aa=0;
		while(a[i]>0){
			aa=min(a[i],a[r]);
			if(c[i]!=c[r])sum+=aa;
			a[i]-=aa;a[r]-=aa;
			if(a[r]==0)r--;
		}
	}
	cout<<sum;
	return 0;
}
