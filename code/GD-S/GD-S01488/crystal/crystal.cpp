#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	int mid=(1+n)>>1;
	for(int i=1;i<=n;i++){
		while(a[i]<a[mid]&&m!=0){
			a[i]++;
			m--;
		}
		if(a[i]==a[mid]){
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<sum;
	return 0;
} 
