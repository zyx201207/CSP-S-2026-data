#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	long long num;
	char c;
}a[N];
long long n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	} 
	long long l=1,r=n;
	long long disl=0,disr=0; 
	while(l<r){
		if(a[l].c!=a[r].c){
			if((a[l].num-disl)<(a[r].num-disr)){
				ans+=a[l].num-disl;
				disr+=a[l].num-disl;
				disl=0;
				++l;
			}else if((a[l].num-disl)>(a[r].num-disr)){
				ans+=a[r].num-disr;
				disl+=a[r].num-disr;
				disr=0;
				--r;	
			}else{
				ans+=a[l].num-disl;
				++l,--r;
				disl=0,disr=0;
			}
		}else{
			if((a[l].num-disl)<(a[r].num-disr)){
				disr+=a[l].num-disl;	
				disl=0;
				++l;
			}else if((a[l].num-disl)>(a[r].num-disr)){
				disl+=a[r].num-disr;
				disr=0;
				--r;
			}else{
				++l,--r;
				disl=0,disr=0;
			}	
		}
	}
	cout<<ans; 
	return 0;
}
