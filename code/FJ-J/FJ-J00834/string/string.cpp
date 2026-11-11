#include<bits/stdc++.h>//Trick||Treat!
#define int long long
using namespace std;
const int max_n=2e5+5;
int n,len;
int ans;
int c[max_n];
char a[max_n];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		scanf(" %c",&a[i]);
		len+=c[i];
	}
	
	int lt=1,rt=n;
	while(lt<rt){
		if(a[lt]==a[rt]){//是回文 
			if(c[lt]==c[rt]){
				c[lt]=0; c[rt]=0;
				lt++,rt--;
			}else if(c[lt]<c[rt]){
				c[rt]-=c[lt];
				c[lt]=0;
				lt++;
			}else if(c[lt]>c[rt]){
				c[lt]-=c[rt];
				c[rt]=0;
				rt--;
			}
		}else{//不是回文 
			if(c[lt]==c[rt]){
				ans+=c[lt];//c[rt]
				c[lt]=0; c[rt]=0;
				lt++;rt--;
			}else if(c[lt]<c[rt]){
				c[rt]-=c[lt];
				ans+=c[lt];
				c[lt]=0;
				lt++;
			}else if(c[lt]>c[rt]){
				c[lt]-=c[rt];
				ans+=c[rt];
				c[rt]=0;
				rt--;
			}
		}
		
			
	}
	
	cout << ans;
	
	return 0;
} 
