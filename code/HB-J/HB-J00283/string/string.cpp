#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],ans=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long head=1,tail=n;
	while(head<tail){
		if(c[head]!=c[tail]) ans+=min(a[head],a[tail]);
		if(a[head]==a[tail]) a[head]=0,a[tail]=0,head++,tail--;
		else if(a[head]<a[tail]) a[tail]-=a[head],a[head]=0,head++;
		else if(a[head]>a[tail]) a[head]-=a[tail],a[tail]=0,tail--;
	}
	cout<<ans;
	return 0;
}
