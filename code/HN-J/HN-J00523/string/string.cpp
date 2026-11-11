#include <bits/stdc++.h> 
#define ll long long 
using namespace std;

int n;
int sum,cnt;

int main (){
	
//	freopen("string.in","r",stdin);
//	freopen("string.out","r",stdout);
	
	cin>>n;	
	int a[n + 1];
	char ss[n + 1],cd;
	
	for (int i = 1;i <= n;i++){
		cin>>a[i]>>cd;
		sum += a[i];
		ss[i] = cd;
		

	}
	for (int i = 1;i <= n;i++){
		if (cnt + a[i] >= sum / 2){
			cnt += a[i];
			break;
		}
		cnt += a[i];
	}	
	
	if (sum % 2 == 0){
//		for (int i = 1;i <= n;i++){
//			
//		}
		cout<<sum - cnt;
	}
	else {
		if (cnt == sum / 2){
			cout<<cnt;	
		}
		if (cnt >= sum / 2 ){
			cout<<sum - cnt;
		}
	}
			
	return 0;
}
