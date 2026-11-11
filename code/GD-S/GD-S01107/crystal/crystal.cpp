#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
long long n , m , a[M] , I , J , ans=1 , sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1 , a+1+n);
	/*for(int i=1;i<=n;i++){//记得注释 
		cout<<a[i]<<" ";
	}
	cout<<"\n";*/
	I=1;
	for(J=2;J<=n;J++){
		sum+=((a[J]-a[J-1])*(J-I));
		//cout<<sum<<" ";//记得注释 
		while(sum>m){
			sum-=(a[J]-a[I]);
			I++;
		}
		//cout<<I<<" "<<J<<endl;//记得注释 
		ans=max(ans , J-I+1);
	}
	cout<<ans;
	
	return 0;
}
//Oct31==Dec25?
