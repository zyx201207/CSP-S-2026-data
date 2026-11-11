#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	vector<int> v;
	vector<int> dp;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	int a1=0,b2=0,c3=0;
	int cnt=n;
	int sum=0;
	while(cnt--){
		for(int i=1+sum;i<=n;i++){
			dp.push_back(v[i]);
			for(int j=1+sum;j<=i;j++){
				if(dp[i]==dp[j]){
					dp.clear();
				}
			}
		}
		for(int i=1+sum;i<=v.size();i++){
			if(v[i]==1){
				a1++;
			}
			else if(v[i]==2){
				b2++;
			}
			else{
				c3++;
			}
		}
		sum++;
	}
	cout<<a1<<" "<<b2<<" "<<c3<<endl;
	return 0;
}
