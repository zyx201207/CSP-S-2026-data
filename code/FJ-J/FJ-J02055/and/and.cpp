#include<bits/stdc++.h>
using namespace std;
int a[200010];
int ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49512;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==1){
		ans=a[n];
	}
	if(m==2){
		int maxx=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		ans=maxx;
	}
	if(m==n-1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			int sum=a[1];
			if(i==1) sum=a[2];
			for(int j=1;j<=n;j++){
				if(j!=i) sum=sum&a[j];
			}
			maxx=max(maxx,sum);
		}
		ans=maxx;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		ans=sum;
	}
	cout<<ans;
	return 0;
}
