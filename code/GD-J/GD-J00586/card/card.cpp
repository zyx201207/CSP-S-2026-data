#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N];
int cnt[N];
int res[N];
int n,m;
void solve(int x){
	int stake[N];
	int r=1;
	for(int i=x;i<=n;i++){
		if(cnt[a[i]]>0){
			while(stake[r]!=a[i]){
				cnt[stake[r]]--;
				stake[r]=0;
				r--;
			}
			cnt[stake[r]]--;
			stake[r]=0;
			r--;
		}
		else{
			r++;
			stake[r]=a[i];
			cnt[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[a[i]]){
			res[a[i]]++;
		}
	}
	memset(cnt,0,sizeof(cnt));
}
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);//Ã¿Ò»¾Ö 
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
	}
	return 0;
} 
	
