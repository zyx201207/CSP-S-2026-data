#include<iostream> 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,cnt=1;long long m;cin>>n>>m;vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=2;i<=n;i++){
		long long sum=(a[i]-a[i-1])*(i-1);
		if(sum<=m){
			m-=sum;
			cnt++;
		}else{
			break;
		}
	}
	cout<<cnt;
	return 0;
} 
