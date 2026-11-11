#include<bits/stdc++.h>
using namespace std;
long long len;
struct node {
	long long a,l,r;
	char f;
};
node h[200005];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>h[i].a>>h[i].f;
		len+=h[i].a;
		h[i].l=h[i-1].r+1;
		h[i].r=h[i].l+h[i].a-1;
	}
	long long g;
	bool o;
	if(len%2==0) o=false,g=len/2;
	else o=true,g=len/2+1;
	long long pp=0;
	for(int i=1; i<=n; i++) {
		if(o) {
			if(h[i].r>g&&h[i].l<g) {
				node ll=h[i];
				h[i].a=g-ll.l;
				for(int j=i+1; j<=n; j++) {
					h[j+1]=h[j];
				}
				h[i+1].f=ll.f;
				h[i+1].a=ll.r-g;
				pp=1;
				break;
			}else if(h[i].l==g){
				h[i].a--;
				break;
			}else if(h[i].r==g){
				h[i].a--;
				break;
			}
		} else {
			if(h[i].r>g&&h[i].l<g) {
				node ll=h[i];
				h[i].a=g-ll.l+1;
				for(int j=i+1; j<=n; j++) {
					h[j+1]=h[j];
				}
				h[i+1].f=ll.f;
				h[i+1].a=ll.r-g;
				pp=1;
				break;
			}else if(h[i].l==g){
				node o=h[i];
				h[i].a=1;
				for(int j=i+1; j<=n; j++) {
					h[j+1]=h[j];
				}
				h[i+1].f=o.f;
				h[i+1].a=o.a-1;
				pp=1;
				break;
			}
		}
	}
	if(pp) ++n;
	long long l=1,r=n;
	long long sum=0;
	while(r>l) {
		if(h[l].a==h[r].a) {
			if(h[l].f!=h[r].f) {
				sum+=h[l].a;
			}
			l++,r--;
		} else if(h[l].a<h[r].a) {
			if(h[l].f!=h[r].f) {
				sum+=h[l].a;
			}
			h[r].a=h[r].a-h[l].a;
			l++;
		} else {
			if(h[l].f!=h[r].f) {
				sum+=h[r].a;
			}
			h[l].a=h[l].a-h[r].a;
			r--;
		}
	}
	cout<<sum;
	return 0;
}
