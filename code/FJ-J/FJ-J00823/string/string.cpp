#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	string y;
} a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long k=1,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		
	}while (k<n){
		if(a[k].x<a[n].x){
			
			if(a[k].y!=a[n].y) ans+=a[k].x;
			a[n].x-=a[k].x;
			k++;
		}
		else {
			if(a[k].x==a[n].x) {
				if(a[k].y!=a[n].y) ans+=a[k].x;
				k++,n--;
			}
			else{
				
				if(a[k].y!=a[n].y) ans+=a[n].x;
				a[k].x-=a[n].x;	
				n--;
			}
		}
	
	}
	cout<<ans;
	return 0;
}
