#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],c[100005],t[100005];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int cnt = 0,sum = 0;
	for(int i = 1;i<=m;i++){
		if(sum+i<=m){
			sum+=i;
			cnt++;
		}
		else{
			break;
		}
		
	}
	cout<<cnt+1;
/*	for(int i = 1;i<=m;i++){
		for(int i = 1;i<=n-1;i++){
			c[i]  =a[i+1]-a[i];
			cout<<a[i+1]<<" "<<a[i]<<" "<<a[i+1]-a[i]<<endl;
		}
		int minn = 1e9,ans = 0;
		for(int j = 1;j<=n;j++){
			if(minn>c[j]&&c[j]!=0){
				minn = c[j];
				ans = j;
			}
		}
		a[ans]++;
		t[a[ans]]++;
		cout<<a[ans]<<" "<<a[i+1]<<" "<<a[i]<<endl;
	}
	int maxn = -1;
	for(int i = 1;i<=100005;i++){
		if(maxn<t[i]){
			maxn = t[i];
		}  
	}
	cout<<maxn;*/
	
	return 0;
}