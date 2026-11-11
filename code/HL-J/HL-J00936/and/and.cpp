#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;

long long all[maxn];

bool cmp(int a,int b){
	return b > a;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    int m,n;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
		cin >> all[i];
	}
	
	sort(all,all + n,cmp);
	int ans = 0;
	
	for(int j = 0;j < n - m + 1;j++){
		if(all[j] <= 2*all[j + m - 1]){
		   cout << j << j + m - 1;
		   int temp = all[j];
		   for(int k = j + 1;k <= j + m - 1;k++){
		   	  temp &= all[k];
		   }
		   ans = max(ans,temp);	
		}
	}
	
	cout << ans;

    return 0;
}
