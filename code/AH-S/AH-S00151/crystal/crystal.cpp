#include <bits/stdc++.h>
using namespace std;
const long long N=1e7;
long long a[N],n,m;
struct Node{
	long long c;
	long long id;
}b[N];
bool cmp(Node x,Node y){
	if(x.c!=y.c) return x.c<y.c;
	return x.id>y.id;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool special_a=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			special_a =false;
		}
	}
	if(special_a==true){
		long long sum=0,ans=0,cnt=0;
		while(ans<=m){
			cnt++;
			ans+=cnt;
			sum++;
		}
		cout<<sum<<endl;
	}
	else{
		sort(a+1,a+n+1);
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				b[i].c+=abs(a[i]-a[j]);
			}
			b[i].id=i;
		}
		sort(b+1,b+n+1,cmp);	
		long long wz=b[1].id;
		long long sum=0,cnt=0;
		for(long long i=wz-1;i>=1;i--){
			if(sum+a[i]-a[i-1]<=m){
				sum+=a[i]-a[i-1];
			}
			cnt++;
		}
		cout<<cnt+1<<endl;
	}
	return 0;
}
