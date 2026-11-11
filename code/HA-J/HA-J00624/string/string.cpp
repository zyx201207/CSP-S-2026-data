#include <bits/stdc++.h>
using namespace std;
struct cc{
	long long l;
	char s;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int o;
	long long w=0;
	cin>>o;
	for(int p=1;p<=o;p++){
		long long x;char xx;
		cin>>x>>xx;
		a[p].l=x;
		a[p].s=xx;
		w+=x;
	}
	int u=1,v=o;
	long long c=0,r1=a[1].l,r2=a[o].l,k=0;
	while(u<v){
		if(a[u].s==a[v].s){
			if(r1<r2){
				k=r1;
				u++;r1+=a[u].l;
			}
			else if(r1==r2){
				k=r1;
				u++;v--;
				r1+=a[u].l;r2+=a[v].l;
			}
			else{
				k=r2;
				v--;r2+=a[v].l;
			}
		}
		else{
			if(r1<r2){
				c+=r1-k;
				k=r1;
				u++;r1+=a[u].l;
			}
			else if(r1==r2){
				c+=r1-k;
				k=r1;
				u++;v--;
				r1+=a[u].l;r2+=a[v].l;
			}
			else{
				c+=r2-k;
				k=r2;
				v--;r2+=a[v].l;
			}
		}
	}
	cout<<c;
	return 0;
}
