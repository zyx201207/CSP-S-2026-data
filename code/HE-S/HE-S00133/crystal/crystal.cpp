#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e5+5;
long long a[N],m;
long long s[N],d[N];
void jiangtian(){
	int t;
	long long ma=-1;
	for(int q=2;q<=n;q++){
		long long ans=0;
		long long cnt=0;
		for(int w=q;w>=1;w--){
			if(ans<m){
				ans+=a[q]-a[w];
				if(ans>m){
					break;
				}
				cnt++;
			}else{
				break;
			}
		}
		ma=max(ma,cnt);
	}
	cout<<ma;
}
void shengwang(){
	long long ma=-1;
	for(int q=1;q<=n;q++){
		if(s[q]<=m){
			ma=q;
		}else{
			break;
		}
	}
	cout<<ma;
}
void solve(){
	cin>>n>>m;
	bool ch=1,xie=1;
	for(int q=1;q<=n;q++){
		cin>>a[q];
		if(q==1){
			continue;
		}
		s[q]=s[q-1]+1;
		if(a[q]-a[q-1]!=1){
			ch=0;
		}
	}
	sort(a+1,a+1+n);
	if(ch){
		shengwang();
		return;
	}
	jiangtian();
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	return 0;
}
