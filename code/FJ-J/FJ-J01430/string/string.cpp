#include<bits/stdc++.h>
using namespace std;
struct v{
	long long num=0;
	string s;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//a=97 z=122;
	v a[20005];
	long long n,sum=0;
	bool f;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num;
		cin>>a[i].s;
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l].num==a[r].num){
			if(a[l].s!=a[r].s){
				sum=sum+a[l].num;
			}
			l++;r--;
		}else 
		if(a[l].num>a[r].num){
			if(a[l].s!=a[r].s){
				sum=sum+a[r].num;
			}
			a[l].num=a[l].num-a[r].num;
			r--;	
		}else 
		if(a[l].num<a[r].num){
			if(a[l].s!=a[r].s){
				sum=sum+a[l].num;
			}
			a[r].num=a[r].num-a[l].num;
			l++;	
		}
	}
	cout<<sum;
	return 0;
}