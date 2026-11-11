#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	int cmp=a[n-1];
	for(int i=n-2;i>=n-m;i--){
		cmp&=a[i];
	}
	cout<<cmp;
	return 0;
}
