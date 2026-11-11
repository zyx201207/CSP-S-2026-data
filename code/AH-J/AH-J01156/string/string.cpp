#include<bits/stdc++.h>
using namespace std;
struct chuan{
	long long num;
	char c;
	long long len;
}a[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;long long l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		a[i].num+=a[i-1].num+a[i].len;	
		}
	long long r=a[n].num;int il=1,ir=n;long long ans=0;
	while(l<=r){
		if(a[il].c!=a[ir].c){
			ans+=min(a[il].len,a[ir].len);
		}
		if(a[ir].len<a[il].len){
				r-=a[ir].len;
				l+=a[ir].len;
				a[il].len-=a[ir].len;				
				ir--;
				}
		else if(a[ir].len>a[il].len){
				l+=a[il].len;
				r-=a[il].len;
				a[ir].len-=a[il].len;
				il++;
				}
		else{
				l+=a[il].len;
				r-=a[il].len;
				il++;
				ir--;
				}

		}
	cout<<ans;
		
	
}
