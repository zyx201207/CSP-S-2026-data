#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,o=0,k=0,cnt=1,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]<a[i+1]){
			o=a[i];
			a[i]=a[i+1];
			a[i+1]=o;
		}
	}
	while(sum!=0){
		if(a[n/2+o]-a[n/2+1+o]>=a[n/2-1-k]-a[n/2-k]){
			if(m>=a[n/2-1]-a[n/2]){
				m-=a[n/2-1]-a[n/2];
				o++;
			}else{
				sum++;
			}	
		}else{
			if(m>=a[n/2]-a[n/2+1]){
				m-=a[n/2]-a[n/2+1];
				k++;
			}else{
				sum++;
			}	
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}
