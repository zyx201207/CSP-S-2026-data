#include<bits/stdc++.h>
using namespace std;

struct s{
	char z;
	long long num;
};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<s> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].z;
	}
	long long l=0,r=n-1;
	long long ans=0;
	while(l<r){
		if(a[l].num>a[r].num){
			if(a[l].z==a[r].z){
				a[l].num-=a[r].num;
			}else{
				ans+=a[r].num;
				a[l].num-=a[r].num;
			}
			r--;
		}else if(a[l].num==a[r].num){
			if(a[l].z!=a[r].z){
				ans+=a[l].num;
			}
            r--;
			l++;
		}else if(a[l].num<a[r].num){
			if(a[l].z==a[r].z){
				a[r].num-=a[l].num;
			}else{
				ans+=a[l].num;
				a[r].num-=a[l].num;
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
