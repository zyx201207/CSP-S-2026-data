#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int endans[N];
int n, m;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+ 1, a + n + 1);
	bool flag = false;
	int ans1 = 0, ans2 = 0;
	if(m == 1){
		cout<< n;
	}else if(m == 2){
		for(int i = 1; i <= n; i++){
			if(!flag){
				ans1 = a[i];
				flag  = true;
				break;
			}else{
				ans2 = a[i];	
			}
		}
		cout<<ans2<<" "<<ans1;
	}
	return 0;
}