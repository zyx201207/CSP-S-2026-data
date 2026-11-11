#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
struct node{
	int m;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].m>>a[i].c;
	int l=1,r=n;
	while(l<=r){
		if(a[l].c!=a[r].c){
			int x=max(a[l].m,a[r].m);
			ans+=x;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
