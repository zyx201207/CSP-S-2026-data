#include<bits/stdc++.h>
using namespace std;
struct lll{
	long long k;
	char l;
}d[99999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long a[200008];
	char c[200008];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		d[i].k=a[i];
		d[i].l=c[i];
	}
	long long o=0,r=1,t=n;
	for(;r<t;){
		if(d[r].l==d[t].l){
			if(d[r].k>d[t].k){
				d[r].k-=d[t].k;
				t--;
			}else if(d[r].k<d[t].k){
				d[t].k-=d[r].k;
				r++;
			}else if(d[r].k==d[t].k){
				r++;
				t--;
			}
		}else if(d[r].l!=d[t].l){
			if(d[r].k>d[t].k){
				d[r].k-=d[t].k;
				o+=d[t].k;
				t--;
			}else if(d[r].k<d[t].k){
				d[t].k-=d[r].k;
				o+=d[r].k;
				r++;
			}else if(d[r].k==d[t].k){
				o+=d[t].k;
				r++;
				t--;
			}
		}
	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
