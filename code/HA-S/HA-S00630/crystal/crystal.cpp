#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,a[N],m,sum=0,num,k=0;
int b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=a[n/2+1];
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			sum=mid-a[i];
		}
		if(a[i]>mid){
			sum=-mid+a[i];
		}
		if(a[i]<=mid&&a[i]>=0){
			sum=mid-a[i];
		}
		b[i]=sum;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(m-b[i]>=0){
			m-=b[i];
		
			t++;
		}
		else{
			continue;
		}
	}
	cout<<t;
	return 0;
}
