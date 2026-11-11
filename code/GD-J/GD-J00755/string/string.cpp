#include<bits/stdc++.h>
using namespace std;
long long p[200005];
char op[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	long long n,tc=0,mid,nv=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i]>>op[i];
		tc+=p[i];
	}
	long long l=1,r=n,sum=0;
	while(l<r){
		if(op[l]!=op[r]) sum+=min(p[l],p[r]);
		if(p[l]==p[r]) l++,r--;
		else if(p[l]>p[r]) p[l]-=p[r],r--;
		else p[r]-=p[l],l++;
	}
	cout<<sum<<"\n";
	return 0;
}
