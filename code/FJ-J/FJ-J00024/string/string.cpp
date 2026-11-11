#include<bits/stdc++.h>
using namespace std;
struct aaa{
	long long k;
	char c;
};
aaa a[2*114514];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long k;
		char c;
		cin>>k>>c;
		a[i].k=k;
		a[i].c=c;
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].k<a[r].k){
				ans+=a[l].k;
				a[r].k-=a[l].k;
				l++;
			}else if(a[l].k>a[r].k){
				ans+=a[r].k;
				a[l].k-=a[r].k;
				r--;
			}else{
				ans+=a[l].k;
				l++;r--;
			}
		}else{
			if(a[l].k<a[r].k){
				a[r].k-=a[l].k;
				l++;
			}else if(a[l].k>a[r].k){
				a[l].k-=a[r].k;
				r--;
			}else{
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
