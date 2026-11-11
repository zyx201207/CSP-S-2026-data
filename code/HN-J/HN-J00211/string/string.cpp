#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
struct P{
	int l,r,cd;
	char a;
}a[N];
int n;
signed main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		int x;
		char ar;
		cin>>x>>ar;
		a[i].l=s+1;
		s+=x;
		a[i].r=s;
		a[i].cd=x;
		a[i].a=ar;
	}
	int x,y;
	if(n%2==0){
		x=n/2;
		y=n/2+1;
	}
	else {
		x=(n+1)/2;
		y=(n+1)/2;
	}
	int ans=0;
	for(int i=1,j=n;i<=x,j>=y;i++,j--){
		if(a[i].a!=a[j].a){
			if(a[i].cd<a[j].cd){
				ans+=a[i].cd;
				a[j].cd=a[j].cd-a[i].cd;
				j++;
			}
			else if(a[i].cd>a[j].cd){
				ans+=a[j].cd;
				a[i].cd=a[i].cd-a[j].cd;
				i--;
			}
			else{
				ans+=a[i].cd;
			}
		}
	}
	cout<<ans;
	return 0;
}
