#include<bits/stdc++.h>
#define st first
#define nd second
#define inf int(1e9+1)
#define INF int(1E18+1)
using namespace std;
typedef long long L;
typedef unsigned long long UL;
int a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,q,ans=-1,cnt;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,[](int x,int y){
		return x>y;
	});
	for(int i=0;i<n;i++){
		cnt=1;
		q=m;
		//cout<<a[i];
		for(int j=i+1;j<n;j++){
			q-=a[i]-a[j];
			if(q>=0){
				cnt++;
				//cout<<' '<<a[j];
			}
		}
		ans=max(ans,cnt);
		//cout<<'/'<<q<<'$'<<cnt<<endl;
	}
	cout<<ans;
	return 0;
}
