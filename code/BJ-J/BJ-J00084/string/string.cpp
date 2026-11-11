#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll num;
	char c;
}a[200005];
int n,m;
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n;
	ll x;
	char y;
	cin>>x>>y;
	a[1].num=x,a[1].c=y;
	m++;
	for(int i=2;i<=n;i++){
		cin>>x>>y;
		if(y==a[m].c){
			a[m].num+=x;
		}else{
			m++;
			a[m].c=y,a[m].num=x;
		}
	}
	int l=1,r=m;
	ll ml=a[l].num,mr=a[r].num;
	while(l<r){
		if(ml<mr){
			mr-=ml;
			if(a[l].c!=a[r].c) ans+=ml;
			l++;
			ml=a[l].num;
		}else if(ml>mr){
			ml-=mr;
			if(a[l].c!=a[r].c) ans+=mr;
			r--;
			mr=a[r].num;
		}else if(ml==mr){
			if(a[l].c!=a[r].c) ans+=ml;
			l++,r--;
			ml=a[l].num,mr=a[r].num;
		}
	}
	cout<<ans;
    return 0;
}
