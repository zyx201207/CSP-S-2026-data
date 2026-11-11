#include<bits/stdc++.h>//Trick||Treat!
#define int long long
using namespace std;
const int max_n=2e5+5;
int n,m;
int a[max_n];
int vs[max_n];



signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	init();
	///
	int ans=0,is=0;
	for(int j=29;j>=0;j--){//        (1LL<<j)
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!is){
				if( (1LL<<j)&a[i] ){
					cnt++;
				}
			}else{
				if( ((1LL<<j)&a[i]) && vs[i] ){
					cnt++;
				}
			}
			
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(!is){
					if( (1LL<<j)&a[i] ){
						vs[i]=1;
					}
				}else{
					if( ((1LL<<j)&a[i]) && vs[i] ){
						vs[i]=1;
					}else{
						vs[i]=0;
					}
				}
			}
			is=1;//¿ªÊ¼Ì°ÐÄ 
			ans+=(1LL<<j);
		}
	} 
	
	printf("%lld",ans);
	
	return 0;
} 
