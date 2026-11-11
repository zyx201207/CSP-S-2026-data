#include<bits/stdc++.h>
using namespace std;
struct node{
	long long s;
	char z;
}a[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].z;
	}
	long long l=1,r=n,cnt=0;
	while(l<n){
		if(a[l].s==0){
			l++;
		}else if(a[r].s==0){
			r--;
		}
		if(a[l].z!=a[r].z){
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				cnt+=a[r].s;
				a[r].s=0;
			}else{
				a[r].s-=a[l].s;
				cnt+=a[l].s;
				a[l].s=0;
			}
		}else{
			
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				a[r].s=0;
			}else{
				a[r].s-=a[l].s;
				a[l].s=0;
			}
		}
	}
	cout<<cnt;
	return 0;
}
