#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}cout<<endl;
	long long c=0;
	for(int r=1,l=1;r<=n;r++){
		l=r-1,c=0;
		while(c+a[r]-a[l]<=m&&l>0){
			c+=a[r]-a[l];
			l--;
		}
		if(r-l>ans){
			ans=r-l;
		//	printf("%d %d %d\n",l,r,ans);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
