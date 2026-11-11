#include<bits/stdc++.h>
#define int long long
#define endl '/n'
using namespace std;
int l[500005];
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	/*for(int i = 0;i < n;i++){
		cout<<l[i];
	}
	int maxb = 0;
	for(int i = n - 1;i >= 0;i--){
		int a = 0;
		int b = 1;
		for(int j = i - 1;j >= 0;j--){
			if(a == m){
				max(maxb,b);
				break;
			}
			if(a > m){
				break;
			}
			a += l[i] - l[j]; 
			b++;
		}
	}*/
	int maxans = 0;
	/*for(int i = n - 1;i >= 0;i--){
		int ans = 1;
		for(int j = 1;i - j >= 0;j++){
			if(l[i] - l[i - j] <= m){
				ans++;
			}
			else{
				break;
			}
		}
		maxans = max(maxans,ans);
	}*/
	
	for(int i = 0;i < n;i++){
		int ans = 1;
		for(int j = 1;i + j < n;j++){
			if(l[i + j] - l[i] <= m){
				ans++;
			}
			else{
				break;
			}
		}
		maxans = max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}
