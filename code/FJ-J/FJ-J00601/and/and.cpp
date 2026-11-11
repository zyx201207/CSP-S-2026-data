#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k[50],ans[200005],answer;
int main(){
	freoprn("and.in",r,stdin);
	freoprn("and.out",w,stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 31;i>=0;i--){
		long long p = pow(2,i);
		int sum = 0;
		int k = 1;
		for(int j = 1;j<=n;j++){
			if((a[j]&p)!=0){
				ans[k] = a[j];
				k++;
				sum++;
			}
		}
		if(sum>=m){
			n = k;
			for(int r = 1;r<=n;r++){
				a[r] = ans[r];
			}
			answer+=p;
		}
	}
	cout << answer;
	return 0;
}







