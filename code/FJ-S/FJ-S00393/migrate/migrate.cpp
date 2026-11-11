/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/
//n*n? 
#include<bits/stdc++.h>
using namespace std;
int n,d,cnt,s,e,sum;
int a[2000005];
void dfs(int now,int stp){
	if(now==e&&stp==sum){
		cnt++;
		return;
	}else if(now==e){
		return;
	}
	for(int i=now+1;i<=n;i++){
		if(a[i]-a[now]<=d){
//			cout<<a[now]<<" "<<a[i]<<endl;
			dfs(i,stp+1);
		}else{
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int l=i,r=i+1;
				sum=1;
				bool flag=0,br=0;
				while(l<=j&&r<=j){
					if(a[l]+d<a[r]){
						if(flag){
							br=1;
							break;
						}
						r--;
						l=r;
						r++;
						sum++;
						flag=1;
					}else{
						flag=0;
						r++;
					}
				}
				if(br){
					continue;
				}
//				cout<<i<<" "<<j<<" "<<sum<<endl;
				e=j;
				cnt=0;
				s=i;
				dfs(i,0);
//				cout<<i<<" "<<j<<" "<<cnt<<endl;
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
