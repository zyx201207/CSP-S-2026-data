#include<bits/stdc++.h>
using namespace std;
#define int long long
using p=pair<int,int>;
const int N=200009;
int a[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	int ma=n,mi=0;
	int ans=0;
	for(int i=30;i>=0;i--){
		int flag1=0;
		bool flag=false;
		int cnt=0;
		for(int j=mi;j<ma;j++){
			if(a[j] & 1<<i){
				cnt++;
			}
			else{
				if(!flag) flag1=j;
				flag=true;
				if(a[j]<=(1<<i)){
					break;
				}
			}
		}
		if(cnt>=m){
			if(flag1==0 && flag==true) flag1=ma-1;
			ma=flag1+1;
			ans+=1<<i;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
