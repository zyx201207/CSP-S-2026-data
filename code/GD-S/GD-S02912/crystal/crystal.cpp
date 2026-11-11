#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N],res = 1,c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i ++){
		c[i] = c[i-1] + a[i];
	}
	for(int i = 1;i<=n;i++){
//		long long k = 0;
		for(int j = res + i; j <= n;j++){
			if(a[j]*(j - i) - c[j-1] + c[i-1] <= m){
				if(j-i+1 > res ){
					res = j-i+1;
				}
//				k += (j-i)*(a[j] - a[j-1]) ; 
//				cout<<a[j]*(j - i) - c[j-1] + c[i-1]<<endl;
			}
			else{
				break;
			}
		}
	}
	cout<<res;
} 
