#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int M=5e5+5;

ll n,m;
ll a[M];
ll res=1;
bool isA=true;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) isA=false;
	} 
	//特殊性质A 
	if(isA){
		if(m%2!=0){
			res=(m+3)/2;
			if(res>=n){
				cout<<n;
				return 0;
			} else{
				cout<<res;
				return 0; 
			}
		}
		else{
			res=(m+2)/2;
			if(res>=n){
				cout<<n;
				return 0;
			} else{
				cout<<res;
				return 0; 
			}
		}
	}
	
	sort(a+1,a+n+1);
//	if(n<=5&&m<=5){
		for(int i=a[1];i<=a[n];i++){
//			int target=a[i]; //目标值 
			ll need=0; //需要的m值 
			ll num=0;
			for(int j=1;j<=n;j++){
				if(need+abs(i-a[j])>m) break;
				need+=abs(i-a[j]);
				num++; //被加到目标值的个数 
//				cout<<i-a[j]<<" ";
			}
			res=max(num,res);
//			cout<<num<<" "<<res<<"";
		}
//	}
	if(res<=n) cout<<res;
	else cout<<n;
	return 0;
} 
