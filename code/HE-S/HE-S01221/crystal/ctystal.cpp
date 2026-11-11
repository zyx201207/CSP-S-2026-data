#include<iostream>
#include<algorithm>
using namespace std;
int main(){
freopen("ctystal.in","r",stdin);
freopen("ctystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	sort(a,a+n);
	int j=n/2;
	int k=1;
	while(m>0){
		if(a[j-k]==a[j]){
			continue;
		}
		else{
			while(a[j-k]!=a[j]){
				a[j-k]++;
				m--;
			}
		}
		k++;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
