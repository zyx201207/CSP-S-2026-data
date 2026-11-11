#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],flag=1,sum=1;
int main(){
	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);

	cin >> n  >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		int k = a[i]+1,fl=1;
		while(k>1){
			if(k%2!=0){
				fl=0;
			}
			k/=2;
		}
		if(fl==0)flag=0;
	}
	if(flag==1){
		sort(a+1,a+n+1);
		cout << a[n-m+1];
	}
}
