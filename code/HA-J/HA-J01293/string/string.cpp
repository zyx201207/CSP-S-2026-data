#include<bits/stdc++.h>
using namespace std;
int n;
struct G{
	long long x;
	char a;
}g[200005];
string m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>g[i].x>>g[i].a;
		
	}
	long long cnt=0;
	char zuo,you;
	long long r = n;
	long long ans = 0;
	if(n/2==0){
		for(int l = 1;l<=n/2;l++){
			
		if(g[l].a==g[r].a){
			if(g[l].x<=g[r].x){
				cnt = g[r].x-g[l].x;
				
				g[r-1].x+=cnt;
			}
			else{
				cnt = g[l].x-g[r].x;
				g[l+1].x+=cnt;	
			}
			r--;
		}
		if(g[l].a!=g[r].a){
			if(g[l].x<=g[r].x){
				cnt = g[r].x-g[l].x;
				ans+=g[l].x;
				g[r-1].x+=cnt;
			}
			else{
				cnt = g[l].x-g[r].x;
				g[l+1].x+=cnt;
				ans+=g[r].x;	
			}
		}
		r--;
	}
	}
	else{
	for(int l = 1;l<=n/2;l++){
			
		if(g[l].a==g[r].a&&cnt==0){
			if(g[l].x<=g[r].x){
				cnt = g[r].x-g[l].x;
				g[r-1].x+=cnt;
			}
			else{
				cnt = g[l].x-g[r].x;
				g[l+1].x+=cnt;	
			}
			r--;
		}
		if(g[l].a!=g[r].a){
			if(g[l].x<=g[r].x){
				cnt = g[r].x-g[l].x;
				ans+=g[l].x;
				g[r-1].x+=cnt;
			}
			else{
				cnt = g[l].x-g[r].x;
				g[l+1].x+=cnt;
				ans+=g[r].x;	
			}
		}
		r--;
	}	
	}
	cout<<ans;
	return 0;
}
