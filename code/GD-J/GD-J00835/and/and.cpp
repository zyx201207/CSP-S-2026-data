#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool is[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		is[i]=true;
	}
	int ans=0;
	for(int j=30;j>=0;j--){
		int num=0;
		for(int i=1;i<=n;i++){
			if(!is[i])  continue;
			int tmp=a[i]&(1<<j);
			if(tmp)  num++;
		}
		if(num>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++){
				int tmp=a[i]&(1<<j);
				if(!tmp)  is[i]=false;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
