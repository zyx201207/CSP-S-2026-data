#include <bits/stdc++.h>

using namespace std;

const int N = 500000 + 100;

int n,m;
int l = 0,r = 0;
int a[N] = {0};
int mo[N] = {0};
int daan[N] = {0};
int ans[N] = {0};
bool f = 0;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	for(int i = n;i >= 1;i--){
	    if(mo[a[i]] == 0){
			mo[a[i]] = i;
		}else{
			l = i,r = max(r,mo[a[i]]);
			
			f = 1;
		}
		
		if(f){
			daan[i]++;
			daan[l + 1]--;
			daan[r + 1]++;
		}else{
			daan[i]++;
		}
	}
	
	for(int i = 1;i <= n;i++){
		daan[i] = daan[i] + daan[i - 1];
		ans[a[i]] = ans[a[i]] + daan[i];
	}
	
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
