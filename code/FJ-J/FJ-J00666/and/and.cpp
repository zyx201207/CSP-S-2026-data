#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20007],maxx=-1;
long long sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=m;i--){
		sum+=(a[i]&a[i+1]);
	}
	cout<<sum/m;
	return 0;
}
