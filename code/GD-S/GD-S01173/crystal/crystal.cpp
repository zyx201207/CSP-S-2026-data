#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[510000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<endl;*/
	long long z[510000]={};
	
	for(int i=1;i<=n;i++){
		
		long long k=m;
		//cout<<k<<endl;
		for(int j=i;j>=1;j--){
			k=k-a[i]+a[j];
			if(k>=0){
				z[i]++;
				
				
				//cout<<k<<endl;
			}
			else break;
			//cout<<a[i]<<" "<<a[j]<<endl;
		}
	}
	//cout<<m<<a[3]<<" "<<a[1]<<endl;

	//cout<<5-4+1;
	sort(z+1,z+n+1);
	cout<<z[n];
	return 0;
}
