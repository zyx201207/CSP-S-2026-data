#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
unsigned long long a[200005],ans;
bool can[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)can[i]=true;
	for(int i=31;i>=1;i--){
		int tmp=0;
		for(int i=1;i<=n;i++)if(((a[i]>>(i-1))&1==0))tmp++;
		if(tmp<m)for(int i=1;i<=n;i++)can[i]=true;
		else ans+=1<<(i-1);
	}
	cout<<ans;
	return 0;
}
