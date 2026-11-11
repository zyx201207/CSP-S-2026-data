#include<bits/stdc++.h>
using namespace std;
const int L=5e5+5;
int n,c;
long long m;
struct hh{
	long long n;
	int m;
	long long l;
}a[L];
bool cmp(hh a,hh b){
	return a.n<b.n;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ont","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i].n;
	sort(a,a+n,cmp);
	a[0].m=1,a[0].l=m;
	for(int i=1;i<n;i++){
		a[i].m=a[i-1].m+1,a[i].l=a[i-1].l-(a[i].n-a[i-1].n)*a[i-1].m;
		while(a[i].l<0){
			a[i].l+=a[i].n-a[i+1-a[i].m].n;
			a[i].m--;
		}
	}
	for(int i=0;i<n;i++) if(a[i].m>c) c=a[i].m;
	cout<<c;
	return 0;
}
