#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt=0,ans=0,gh=0;
int a[1000005];
int fly(int s,int b,int e){
	if((b-s)&e==0){
		ans=min(ans,(b-s)&e);
	}else{
		ans=min(ans, fly( s, b-(b-s)/2, e-1));
	}
	return ans;
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		gh=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			int u=a[j];
			for(int h=n;h>=j;h--){
				int	v=a[h];
				ans=fly(u,v,d);
				if(cnt==ans){
					gh++;
				}
				cnt=ans;
			}
		}
		cout<<gh;
	}
	return 0;
}

