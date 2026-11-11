#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int n,d,ans=0,minn=1e18,www=0;
void bfs(int x,int y,int num){
	if(x==y){
		minn=min(minn,num);
		return;
	}
	for(int i=y;i>x;i--){
		if(d+a[x]>=a[i]){
		//	cout<<d<<" "<<a[x]<<" "<<a[i]<<endl;
			if(num+1>minn)continue;
			bfs(i,y,num+1);
			break;
		}
	}
	
}
void bfs2(int x,int y,int num){
	if(x==y){
		if(num==minn)www++;
		return;
	}
	for(int i=y;i>x;i--){
		if(d+a[x]>=a[i]){
			if(num+1>minn)return;
			bfs2(i,y,num+1);
		}
	}
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool tepan1=1;
		int s=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=s){
				tepan1=0;
			}
		}		
		if(n<=60){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					minn=1e18;
					bfs(i,j,0);
					www=0;
					bfs2(i,j,0);
					if(www==2)ans++;
				//	cout<<i<<" "<<j<<" "<<minn<<endl;
				}
			}
			cout<<ans<<" "<<clock()<<endl;
			continue;
		}
		if(tepan1){
			for(int l=1;l<=n-3;l++){
				if(a[l+3]-a[l]<=d*2&&a[l+3]-a[l]>d){
					ans++;
				}	
			}
			cout<<ans<<endl;
			continue;
		}

		int wn=0;
		for(int i=1;i<=n;i++){				
			int cen=lower_bound(a+1,a+1+n,a[i]+d)-a;
			cen--;
			for(int j=i+1;j<=n;j++){
				wn=0;
				for(int k=max(cen-10,1ll);k<=min(cen+10,n);k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d)wn++;
				}
				if(wn==2)ans++;		
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}
//16pts

//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
