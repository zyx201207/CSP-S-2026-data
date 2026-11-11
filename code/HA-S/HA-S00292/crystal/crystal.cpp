#include <bits/stdc++.h>
using namespace std;
int a[500005];
int d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	int c=1,b=0,maxx=-1000000,x=0,i=0,j=0;
		for(int l=0;l<n;l++){
			for(;;){
				x++;
				if(j==i) j++;
				if(a[i]==a[j]) {
					c++;
					//cout<<a[i]<<a[j]<<endl;
					i++;
					j++;
					//cout<<a[j]<<' '<<a[i]<<endl<<c<<endl;
				}
				else{
					b+=a[j]-a[i];
					a[i]+=a[j]-a[i];
					for(int k=i+1;k<j;k++){
						b+=a[j]-a[k];
						a[k]+=a[j]-a[k];
						
					}
					
								
				}
				//cout<<b<<endl;
				
				if(b>=m) break;
				if(x==n) break;
			}
			if(c>=maxx){
				maxx=c;
			}a[i]=d[i];
			if(b>=m) break;
		}
	cout<<maxx;
	return 0;
}
