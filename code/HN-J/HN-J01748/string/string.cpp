#include <bits/stdc++.h>
using namespace std;

int n;
struct s{
	long long chang;
	char shu;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i].chang>>a[i].shu;
	}
	if(n==2){
		cout<<max(a[1].chang,a[2].chang);
	}
	long long cnt=0;
	for(int i=0;i<=n/2;i++){
		if(a[i].shu!=a[n-i].shu){
			cnt+=min(a[i].chang,a[n-i].chang);
			a[i].chang-=min(a[i].chang,a[n-i].chang);
			if(a[i].chang>0){
				a[i+1].chang+=a[i].chang;
			}
		}
	}
	cout<<cnt;
	return 0;
}
