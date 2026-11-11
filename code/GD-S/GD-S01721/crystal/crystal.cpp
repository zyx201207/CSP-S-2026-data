#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005];
int cha;
bool flag;

int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==1) cha=a[i]-a[i-1];
		if(a[i]>1 && cha!=a[i]-a[i-1]) flag=1;
	}
	
	if(!flag){
		for (int i=1;i<=n;i++){
			m-=(i*cha);
			if(m<0){
				cout << i;
				return 0;
			}
		}
	}
	
	sort(a,a+n);
	
	int maxn=-1;
	
	for (int i=n-1;i>=0;i--){
		int pos=m;
		for (int j=i;j>=0;j--){
			pos=pos-(a[i]-a[j]);
			if(pos<0){
				maxn=max(maxn,i-j);
			}
		}
	}
	
	cout << maxn;
	return 0;
}
