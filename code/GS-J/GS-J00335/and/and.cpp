#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],m,mid[100005],z=1,i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i+=1){
		for(int j=i+1;j<=n;j++){
			mid[z]=a[i]&a[j];
			z++;
		}
	}
	sort(mid,mid+z);
	cout<<mid[1];
	return 0;
}
