#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long sum=0;
int n;
struct le{
	long long lenth;
	char zifu;
}a[N];
void df(){
	int l=1,r=n;
	while(l!=r){
		if(a[l].zifu!=a[r].zifu){
			if(a[l].lenth>a[r].lenth){
				sum+=a[r].lenth;
				a[l].lenth-=a[r].lenth;
				r--;
			}
			else if(a[l].lenth<a[r].lenth){
				sum+=a[l].lenth;
				a[r].lenth-=a[l].lenth;
				l++;
			}
			else{
				sum+=a[l].lenth;
				l++;
				r--;
			}
		}
		else if(a[l].zifu==a[r].zifu){
			if(a[l].lenth>a[r].lenth){
				a[l].lenth-=a[r].lenth;
				r--;
			}
			else if(a[l].lenth<a[r].lenth){
				a[r].lenth-=a[l].lenth;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		//cout<<sum<<endl;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].lenth>>a[i].zifu;
	df();
	cout<<sum;
	return 0;
} 
