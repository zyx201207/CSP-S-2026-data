#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0);
	vector<bool> f(n+1,1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,cnt=0;
	for(int i=31;i>=0;i--){
		cnt=0;
		vector<int> cannot;
		for(int j=1;j<=n;j++){
			if(f[j]&&(a[j]&1<<i)){
				cnt++;
			}else{
				cannot.push_back(j);
			}
		}
		if(cnt>=m){
			ans+=1<<i;
			for(int j:cannot){
				f[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
