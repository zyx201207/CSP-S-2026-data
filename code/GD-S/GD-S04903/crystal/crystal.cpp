#include<bits/stdc++.h>
using namespace std;
	long long n,m;
	long long a[10000000];
	long long maxn=10000000;
	long long k=m;
	long long sum=0;
int main(){
	/*
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	*/
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(k==0){
			break;
		}else{
		sort(a+1,a+1+n);
		a[1]++;
		k--;
		}	
	}
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				sum++;
			}
		}
		cout<<sum;
		/*
	fclose(stdin);
	fclose(stdout);
	*/
	return 0;
}
