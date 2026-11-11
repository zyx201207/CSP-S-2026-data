#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long n , m , a[M] , ans , k , maxx , wei=1 , c[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx , a[i]);
	}
	for(int i=maxx;i>0;i/=2){
		k++;
	}
	wei=wei<<(k-1);
	for(;wei>0;wei/=2){
		//cout<<wei<<" ";
		int t=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0&&((a[i]&wei)!=0)){
				t++;
			}
		}
		//cout<<t<<endl;
		if(t>=m){
			ans+=wei;
			for(int i=1;i<=n;i++){
				if((a[i]&wei)==0) c[i]=1;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
