//GZ-J00293 »Æçûä¿ 
#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int i = 1,j = n;
	while(i < j){
		if(c[i] != c[j])
			ans += min(a[i],a[j]);
		if(a[i] > a[j]){
			a[i] -= a[j];
			j--;
		}else if(a[i] < a[j]){
			a[j] -= a[i];
			i++;
		}else{
			j--;
			i++;
		}
	}
	cout << ans;
	return 0;
}
