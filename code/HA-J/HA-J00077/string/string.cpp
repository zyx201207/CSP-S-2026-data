#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n;
int a[N];
char c[N];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int p=1,q=n,num;
	while(p<q){
		num=min(a[p],a[q]);
		if(c[p]!=c[q]) ans+=num;
		a[p]-=num;
		a[q]-=num;
		if(!a[p]) p++;
		if(!a[q]) q--;
	}
	cout<<ans;
	
	return 0;
}
