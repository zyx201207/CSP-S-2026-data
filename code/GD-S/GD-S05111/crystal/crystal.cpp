#include<bits/stdc++.h>
using namespace std;
const int N=500001;
long long a[N];
int n,id,s,ma=0;
long long m,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		id=i;
		while(sum<=m){
			id++;
			sum+=(a[id]-a[id-1])*(id-i);
		}
		s=id-i;
		if(s>ma) ma=s;
	}
	cout<<ma;
	return 0;
}
