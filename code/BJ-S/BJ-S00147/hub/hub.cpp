#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
	long long id,ins;
}a[500005];
node ist[500005];
bool cmp(node x,node y){
	return x.ins<y.ins;
}
bool idcmp(node x,node y){
	return x.id<y.id;
}
long long f,ans=0,idx=1,sum;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].ins;
		sum+=a[i].ins;
	}
	sum/=n;
	int minn=INT_MAX,mid;
	sort(a+1,a+n+1,cmp);
	sort(a+1,a+n+1,idcmp);
	for(int i=1;i<=n;i++){
		ist[i].ins=abs(sum-a[i].ins);
		if(minn>ist[i].ins){
			minn=ist[i].ins;
			mid=a[i].ins;
		}
	}
	for(long long i=1;i<=n;i++){
		ist[i].ins=abs(mid-a[i].ins);
	}
	sort(ist+1,ist+n+1,cmp);
	while(idx<=n&&f<m){
		if(ist[idx].ins>=m){
			cout<<ans;
			return 0;
		}else{
			f+=ist[idx].ins;
			ans++;
		}
		idx++;
	}cout<<ans;
	return 0;
}
