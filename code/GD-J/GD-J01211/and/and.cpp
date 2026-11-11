#include<bits/stdc++.h>
using namespace std;
bool cmp(const int& a, const int& b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		int ma = 0;
		if(m == 1){
			for(int i = 0;i<n;i++){
				ma = max(ma,a[i]);
			}
			cout<<ma;
			return 0;
		}
		else if(m == n){
			int ans = a[0];
			for(int i = 1;i<n;i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
		else if(m == 2){
			int tmp;
			for(int i = 0;i<n-1;i++){
				tmp = a[i];
				for(int j = i+1;j<n;j++){
					tmp&=a[j];
					ma = max(ma,tmp);
				}
			}
			cout<<ma;
			return 0;
		}
	}
	else{
		if(m == n-1){
			sort(a.begin(),a.end(),cmp);
			int ma = 0;
			int tmp;
			for(int i = 0;i<n;i++){
				tmp = INT_MAX;
				for(int j = 0;j<n;j++){
					if(j == i) continue;
					tmp&=a[j];
				}
				ma = max(ma,tmp);
			}
			cout<<ma;
			return 0;
		}
		cout<<-1;
	}
	return 0;
}
