#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+9;
struct node{
	int x;
	char y;
};
bool cmp(int a,int b){
	return a>b;
}
int a[N];
signed main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		int x=ans,y=a[i];
		int cnt=1,ans2=0;
		while(x!=0&&y!=0){
			int u=x%2;
			x/=2;
			int v=y%2;
			y/=2;
			if(u==v&&u==1){
				ans2+=cnt;
			}
			cnt*=2;
		}
		ans=ans2;
	}
	cout<<ans<<endl;
	return 0;
}
