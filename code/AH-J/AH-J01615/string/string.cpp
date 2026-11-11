#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int l=0;
	char s;
}a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].l>>a[i].s;
		b[n-1-i].l=a[i].l;
		b[n-1-i].s=a[i].s;
	}
	int k1=0,k2=0;
	long long ans=0;
	while(!(k1>n-1 || k2>n-1)){
		if(a[k1].s==b[k2].s){
			if(a[k1].l==b[k2].l){
				k1++;
				k2++;
				continue;
			}
			if(a[k1].l>b[k2].l){
				a[k1].l-=b[k2].l;
				k2++;
				continue;
			}
			else{
				b[k2].l-=a[k1].l;
				k1++;
				continue;
			}
		}
		else{
			if(a[k1].l==b[k2].l){
				ans+=a[k1].l;
				k1++;
				k2++;
				continue;
			}
			if(a[k1].l>b[k2].l){
				ans+=b[k2].l;
				a[k1].l-=b[k2].l;
				k2++;
				continue;
			}
			else{
				ans+=a[k1].l;
				b[k2].l-=a[k1].l;
				k1++;
				continue;
			}
		}
	}
	ans/=2;
	cout<<ans<<endl;
	return 0;
}
