#include<bits/stdc++.h>
using namespace std;
long long a[1001];
int n,m;

void show(int l, int r){
	int mid=(l+r)/2;
	int sum=0,cnt=0;
	for(int i=1;i<=r;i++){
		if(sum<m){
			sum+=(a[mid]-a[i]);
			cnt++;
		}
	cout<<sum<<" "<<cnt<<" ";	
	}
	
}//Oct31==Dec25?
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	show(1,n);
	
} 
