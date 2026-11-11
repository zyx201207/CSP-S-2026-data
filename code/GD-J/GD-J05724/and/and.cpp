#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long sum=0,mx=-1;
	for(int i=0;i<m;i++){
		mx=-1;
		for(int j=0;j<n;j++){
			mx=max(mx,a[j]);
		}
		for(int j=0;j<n;j++){
			if(mx==a[j]){
				a[j]=-1;
				break;
			}
		}
		if(i==1){
			sum=mx;
		}else{
			sum=sum&mx;
		}
	}
	cout<<sum;
    fclose(stdin);
   	fclose(stdout);	
    return 0;
}
