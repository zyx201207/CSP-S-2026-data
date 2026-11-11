#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200005],maxx=-1,minn=1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx<<"\n";
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx<<"\n";
		return 0;
	}
	if(m==n){
		int x=a[1];
		for(int i=1;i<=n;i++){
			x&=a[i];
		}
		cout<<x<<"\n";
		return 0;
	}
	if(m==n-1){
		int minn;
		for(int i=1;i<=n;i++){
			int sum=0,num=1e9,x=a[i];
			while(x){
				if(x%2==1){
					sum++;
				}
				x/=2;
			}
			if(sum<num){
				num=sum;
				minn=a[i];
			}
		}
		int x;
		if(minn==a[1]){
			x=a[2];
			for(int i=2;i<=n;i++){
				x&=a[i];
			}
		}
		else{
			x=a[1];
			for(int i=1;i<=n;i++){
				if(minn==a[i]) continue;
				x&=a[i];
			}
		}
		cout<<x<<"\n";
		return 0;
	}
	cout<<minn;
	return 0;
}
