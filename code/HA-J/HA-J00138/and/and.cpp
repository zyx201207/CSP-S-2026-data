#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200000],max_x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	if(m==1){
		long long x_max=0,x;
		while(n--){
			cin>>x;
			x_max=max(x,x_max);
		}
		cout<<x_max;
		return 0;
	}
	if(m==n){
		long long x;
		cin>>x;
		n--;
		max_x=x;
		while(n--){
			cin>>x;
			max_x=max_x&x;
		}
		cout<<max_x;
		return 0;
	}
	//if(m==2){
		for(int i=0;i<n;i++)	cin>>a[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				max_x=max(max_x,a[i]&a[j]);
			}
		}
		cout<<max_x;
		return 0;
	//}
	
	
	return 0;
}
