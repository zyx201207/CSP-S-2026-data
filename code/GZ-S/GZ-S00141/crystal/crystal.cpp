//GZ-S00141 遵义市新蒲中学 王墨霖 
#include<bits/stdc++.h>
using namespace std;
long long a[500005],cz[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	long long h=1,l=n,w=0;
	while(h<=l){
		long long z=h+(l-h)/2,p=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=a[z]){
				p++;
				cz[p]=a[z]-a[i];
			}else{
				break;
			}
		} 
		long long m1=m,q=0;
		while(p>0  && m1-cz[p]>=0){
			if(m1-cz[p]>=0){
				m1-=cz[p];
				p--;
				q++;
			}else{
				break;
			} 
		} 
		if(q>=z){
			h=z+1;
		}else{
			l=z-1;
		}
		w=max(w,q);                            
		for(int i=1;i<=q+p;i++){
			cz[i]=0;
		} 
	}
	cout<<w;
	return 0;
}
