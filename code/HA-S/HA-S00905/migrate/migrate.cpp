#include<bits/stdc++.h>
using namespace std;
int c,t;
int g[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
	int n,d,a[100005];
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	 
	int cnt=0,flag[10005],u;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]<=d){
				flag[j]++;
				if(a[i]<0){
					d+=a[i+1]-a[i];
				}
				else{
					d-=a[i+1]-a[i];
				}
			}
		} 
		 
	}
		sort(flag+1,flag+n+1);
	for(int i=1;i<=n;i++){
		if(flag[i]==flag[i+1]){
			cnt++;
		}
			if(cnt>=2){
		u++;
		cnt-=2;
	}
	}

	 
cout<<u<<'/n';

}
//for(int i=1;i<=t;i++){
//	cout<<g[i]<<'\n';
//}
	return 0;
}


