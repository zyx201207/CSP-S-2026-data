#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5;
ll a[5*MAX+3],b[5*MAX+3];
ll sum,sum1,sum4;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	ll p=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	} 
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int sum3=0;
		if(a[i]==a[i-1]) continue;
		for(int j=i-1;j>=0;j--){
			sum3++;
			p-=abs(a[i]-a[j]);
			if(p<=0){
				break;
			}
		}
			if(sum3>sum1){
				sum1=sum3;
				sum4=a[i];
			}if(sum3==sum1){
				if(b[sum4]<b[a[i]]){
					sum4=a[i];
				}
			}sum=0;p=m;
		}
	
	cout<<b[sum4]+sum1;
	return 0;
} 
