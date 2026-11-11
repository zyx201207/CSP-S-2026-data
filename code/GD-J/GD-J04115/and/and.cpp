#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;		
	}
	else if(m==n-1){
		int x=INT_MAX,y=1,z,cnt;
		for(int i=1;i<=n;i++){
			cnt=0;
			z=a[i];
			while(z){
				z=z-int(pow(2,int(log2(z))));
				cnt++;
			}
			if(cnt<x)y=i,x=cnt;
		}
		ans=INT_MAX;
		cout<<y<<' ';
		for(int i=1;i<=n;i++){
			if(i==y)continue;
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		int k=0;
		for(int i=31;i>=0;i--){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(((k|(1<<i))&a[j])==(k|(1<<i)))cnt++;
			}
			if(cnt>=2)k=k|(1<<i);
		}
		cout<<k;
	}
	else {
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
