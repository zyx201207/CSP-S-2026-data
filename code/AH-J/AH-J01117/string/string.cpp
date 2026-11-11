#include<bits/stdc++.h>
using namespace std;
char a[300005];
long long nu[300005];
long long l=1,r,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>r;
	for(int i=1;i<=r;i++){
		cin>>nu[i]>>a[i];
	}
	while(l<r){
		if(a[l]!=a[r]) sum+=min(nu[l],nu[r]);
		//cout<<l<<" "<<r<<"\n"; 
		//cout<<nu[l]<<" "<<nu[r]<<"\n";		
		if(nu[l]>nu[r]){
			nu[l]-=nu[r];
			r--;
		}
		else if(nu[l]<nu[r]){
			nu[r]-=nu[l];
			l++;
		}
		else if(nu[l]==nu[r]){
			r--;
			l++;
		}

	}
	cout<<sum;
	return 0;
}

