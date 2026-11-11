#include <bits/stdc++.h>
using namespace std;
struct node {
	long long s;
	char z;
}a[200008];
long long sum; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].z;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].s==a[r].s){
			if(a[l].z!=a[r].z){
				sum+=a[l].s;
				l++;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else if(a[l].s!=a[r].s){
			if(a[l].s>a[r].s){
				if(a[l].z==a[r].z){
					a[l].s-=a[r].s;
					r--;
				}
				else{
					a[l].s-=a[r].s;
					sum+=a[r].s;
					r--;
				}
			}
			else if(a[l].s<a[r].s){
				if(a[l].z==a[r].z){
					a[r].s-=a[l].s;
					l++;
				}
				else{
					a[r].s-=a[l].s;
					sum+=a[l].s;
					l++;
				}
			}
		}
		
	}
	cout<<sum;
	return 0;
}
