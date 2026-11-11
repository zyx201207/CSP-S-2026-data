#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct duan{
	long long a;
	char s;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	char s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		if(s==b[i-1].s){
			b[i-1].a+=a;
		}
		else {
			b[i].a=a;
			b[i].s=s;
		}
	}
	duan ll=b[1],lr=b[n];
	int l=1,r=n;
	while(r>l){
		if(ll.s!=lr.s){
			if(ll.a>lr.a){
				ans+=lr.a;
				ll.a=ll.a-lr.a;
				r--;
				lr=b[r];
			}
			else {
				ans+=ll.a;
				lr.a=lr.a-ll.a;
				l++;
				ll=b[l];
			}
		}
		else{
			if(ll.a>lr.a){
				ll.a=ll.a-lr.a;
				r--;
				lr=b[r];
			}
			else {
				lr.a=lr.a-ll.a;
				l++;
				ll=b[l];
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}