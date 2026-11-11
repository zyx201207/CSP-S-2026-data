#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num=1,max;
	int a[500500]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]-a[0]>m){
			max=i;
			break;
		}
	}
	n-=max;
	while(m--){
		sort(a,a+n);
		a[0]++;
	}
	sort(a,a+n);
	int i=0;
	while(1){
		if(a[i]!=a[i+1]){
			break;
		}
		num++;
		i++; 
	}
	cout<<num;
	return 0;
}
