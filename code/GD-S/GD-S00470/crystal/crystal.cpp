#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n,x,sum,ans,a[N];
ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i ++){
		scanf("%d",a + i);
	}sort(a + 1,a + n + 1);
	for(int i = n;i >= 1;i --){
		sum = 1,x = m;
		for(int j = i - 1;j >= 1;j --){
			if(a[j] + x >= a[i]){
				x -= (a[i] - a[j]);
				sum ++;
			}else{
				break;
			}
		}ans = max(sum,ans);
	}printf("%d",ans);
	return 0;
}
/*
45ртио 
*/
