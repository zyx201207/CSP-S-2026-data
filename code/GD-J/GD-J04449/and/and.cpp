#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5; 
int n,m,a[N],last,ans,sum[N];
vector<int>s[50];
void trn(int x){
	int cnt=0,y=x;
	while(x){
		cnt++;
		if(((x>>1)<<1)!=x){
			sum[cnt]++;
			s[cnt].push_back(y);
		}
		x=(x>>1);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int id=40;
	while(1){
		for(int i=1;i<=40;i++){
			sum[i]=0;
			s[i].clear();
		}
		for(int i=1;i<=n;i++){
			trn(a[i]);
		}
		int flag=1;
		for(int i=id-1;i>=1;i--){
			if(sum[i]>=m){
				id=i;
				flag=0;
				break;
			}
		}
		
		if(flag) break;
		int ss=0;
		for(int ed:s[id]) a[++ss]=ed;
		ans+=(1<<(id-1));
		n=sum[id];
	}
	cout<<ans;
	return 0;
}
