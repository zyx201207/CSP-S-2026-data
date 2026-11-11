#include <bits/stdc++.h>
using namespace std;

long long m,n,d,c;
int a[200005];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> m >> n;
	for(int i=0;i<m;i++){
		cin >> d;
		a[i]=d;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m-i;j++){
			if(a[i]<=a[i+j]){
				c=a[i] and a[i+j];
			}
			else{
				c=a[i+j] and a[i];
			}
			if(c>ans){
				ans=c;
			}
		}
	}
	cout << ans;
	return 0;
}
