#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int pre[500005];
bool chk(int x,int y){//x-y vs a[y]
	int d=pre[y]-pre[x-1];
	int k=(y-x+1)*a[y];
	if(k-d<=m) return 1;
	else return 0;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int num=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(chk(mid,i)){
				num=i-mid+1;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,num);
	}
	cout<<ans;
//	freopen("crystal6.ans","r",stdin);
//	int x;
//	cin>>x;
//	if(ans==x) cout<<"Accept";
//	else cout<<"Wrong answer";
} 

