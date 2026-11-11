#include <bits/stdc++.h>
using namespace std;
int n,a[10000000],maxn=0,minn=0;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int cnt=1,p=0,q=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxn<a[i]){
			maxn=a[i];
			p=i;
		}
		if(minn>a[i]){
			minn=a[i];
			q=i;
		}
	}
	if(maxn==0){
		p=n;
		maxn=a[n];
	}
	if(minn==0){
		q=1;
		minn=a[1];
	}
	
	for(int i=n;i>=1;i--){
		if(maxn>m){
			p=i-1;
			maxn=a[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++){
			if(abs(maxn)+abs(minn)>m){
				if(maxn-a[i+1]>m) maxn=a[p-1];
			}
		}
	} 
	for(int i=1;i<=m;i++){                                                                                                                                                                                                                                                                                                                                  
		if(maxn-minn<=m) {	
			m-=maxn-minn;
			cnt++;
			minn=a[i+1];
			cout<<cnt<<" "<<minn<<endl;
		}
		else break;
	}
	cout<<cnt;
	return 0;
}
