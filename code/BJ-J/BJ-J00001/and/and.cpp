#include<bits/stdc++.h>
using namespace std;
int a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(a[j]&(1<<i))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=0;j<n;j++){
				if((a[j]&(1<<i))==0)a[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}