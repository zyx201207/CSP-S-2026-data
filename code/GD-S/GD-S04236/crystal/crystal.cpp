#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m,ans,cnt=1,a[]={};
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[n];
		ans+=a[n];
		if(ans==a[n]||ans-1==a[n]||ans+1==a[n]){
			cnt++;
		}else{
			break;
		}
	} 
		cout << cnt <<endl;
	return 0;
} 
