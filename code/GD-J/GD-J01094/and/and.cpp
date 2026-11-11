#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n,k;
int ans;
int val[N];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>val[i];
	sort(val+1,val+n+1,cmp);
	for(int i=30;i>=0;i--){
		int j=1;
		while((!(val[j]&(1<<i)))&&j<=n) j++;
		if(i==0&&(!(val[j]&(1<<i)))) cout<<0;
		if(!(val[j]&(1<<i))) continue;
		int t=val[j];
		for(int cur=1;cur<=k;cur++,j++){
			t&=val[j];
			if(j>n) break;
		}
		if(t&(1<<i)){
			cout<<t;
			break; 
		}
		if(i==0) cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
