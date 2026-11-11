#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500099];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool bool_=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			bool_=0;
			break;
		}
	}
	int k=1;
	if(!bool_){
		for(bool p=0;k<=n;k++){
		int l=0,r=n,mid=(l+r)/2;
		while(l<r){
			int sum1=0,sum2=0;
			for(int i=l+1;i<l+k;i++){
				sum1+=a[i]-a[l];
			}for(int i=r-1;i>r-k;i--){
				sum1+=a[r]-a[i];
			}
			if(sum1>m)sum1=-1;
			if(sum2>m)sum2=-1;
			if(sum1==-1&&sum2==-1){
				p=1;
				break;
			}
			if(sum1>sum2){
				r=mid-1;
				mid=(l+r)/2;
			}else{
				l=mid+1;
				mid=(l+r)/2;
			}		
		}if(p)break;
		}
	}
	
	if(bool_){
		while(k*(k-1)/2*(a[1]-a[0])<=m)k++;
		
	}k--;
	cout<<k;
	return 0;
}
/*
5 19
1 3 5 7 9
*/
