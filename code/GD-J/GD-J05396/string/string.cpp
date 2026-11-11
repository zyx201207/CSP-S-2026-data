#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	long long sum;
}a[200005];
long long ans,n,maxx=-1;
long long lp=1,l=1,rp,r=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	rp=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
		maxx+=a[i].sum;
	}
	for(int i=1;i<=maxx/2+maxx%2;i++){
		if(l>a[lp].sum){
			lp++;
			l=1;
		}
		if(r>a[rp].sum){
			rp--;
			r=1;
		}
		if(a[lp].c!=a[rp].c){
			ans++;
			//cout<<lp<<" "<<l<<endl;
		}
		l++;
		r++;
	}
	cout<<ans;
	return 0;
}
