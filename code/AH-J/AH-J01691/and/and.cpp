#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],m,wei[N],num[32][N],shai[32][N][2],cnt[32],t,mx,last,ans[32],er[32],anss;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	memset(wei,0,sizeof(wei));
	memset(num,0,sizeof(num));
	memset(ans,0,sizeof(ans));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		t=a[i];
		while(t){
			num[wei[i]+1][i]=t%2;
			t/=2,wei[i]++;
		}
	}
	mx=wei[n-m+1]+1;
	cnt[mx]=n,last=mx;
	for(int i=1;i<=n;i++)shai[mx][i][0]=i,shai[mx][i][1]=a[i];
	while(mx--){
		for(int i=1;i<=cnt[last];i++)if(num[mx][shai[last][i][0]]==1)shai[mx][++cnt[mx]][0]=shai[last][i][0],shai[mx][cnt[mx]][1]=shai[last][i][1];
		if(cnt[mx]>=m)last=mx,ans[mx]=1;
	}
	er[1]=1;
	for(int i=2;i<=31;i++)er[i]=2*er[i-1];
	for(int i=31;i>=1;i--)anss+=ans[i]*er[i];
	cout<<anss<<endl;
	return 0;
}
