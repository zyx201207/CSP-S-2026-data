#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000005],ans;
int dfs(int a,int b,int c,int d){
	if(a==b&&c==d)return 1;
	int go=a,sum=0;
	while(go+1<=b&&x[go+1]-x[a]<=d){
		sum+=dfs(go,b,c,d+1);
	}
	return sum;
}
int dd(int a,int b){
	int go=a,aa=a,cnt=0;
	while(go<b){
		while(go+1<=b&&x[go+1]-x[aa]<=d)go++;
		aa=go,cnt++;
	}
	return dfs(a,b,cnt,0);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
	if(c<11){
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n-2;i++){
				for(int j=i+2;j<=n;j++){
					if(dd(i,j)==2)ans++,cout<<i<<j;
				}
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
}
