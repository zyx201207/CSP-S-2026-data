#include<bits/stdc++.h>
using namespace std;
long long a[1000010]={};
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cin>>a[0];
    int k,f;
    for(int i=1;i<n;i++){
    	cin>>a[i];
	}
	k=a[1]-a[0];
	sort(a,a+n);
	f=m/k;
	int ans=0;int p=1;
	while(f!=0){
		f=f-p;
		p++;
		ans++;
	}
	cout<<ans;	




    return 0;

}
