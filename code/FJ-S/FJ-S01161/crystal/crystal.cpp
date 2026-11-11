#include<bits/stdc++.h> 
using namespace std;
int n,a[500005];
long long m,sum,maxx=-1,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d=i,sum=0;
		while(d<n){
			d++;
			sum+=a[d]-a[i];
			if(sum>m) {d--;
				break;}
		}maxx=max(maxx,d-i+1);
	}cout<<maxx;
	return 0;
}
