//GZ_S00159  安顺市第二高级中学 郑焕恒
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define int long long
//using in8=_int128;
//using ll=long long;
const int M=6e5+7;
using namespace std;
int n,m,a[M],s[M],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w,",stdout);
	//freopen("t11.in","r",stdin);
	//freopen("t11.out","w",stdout);
	 scanf("%lld %lld",&n,&m);
	 //cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	scanf("%lld",&a[i]);
	 	//cin>>a[i];
	 }
	 sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	/*for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			int he=s[i-1]-s[j-1];
			if(a[i]*(i-j)-he<=m){
				ans=max(ans,i-j+1);
			}else break;
		}
	}*/
	
	int h=1;
	for(int i=1;i<=n;i++){ 
		int he=s[i]-s[h-1];
			while(a[i]*(i-h+1)-he>m&&h<=i){
				h++;
				he=s[i]-s[h-1];
			}ans=max(ans,i-h+1);
	}
	printf("%lld",ans);
	//cout<<ans;
	return 0;
}