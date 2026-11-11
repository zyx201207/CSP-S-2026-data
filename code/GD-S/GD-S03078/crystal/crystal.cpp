#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],mm,sum,MAX;
bool chk1(){
	int d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			return false;
		}
	}return true;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(chk1()){
		for(int i=n;i>=1;i--){
			if(m-(a[n]-a[i])>=0){
				m-=(a[n]-a[i]);
				sum++;
			}else{
				break;
			}
		}cout<<sum;
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			mm=m,sum=0;
			for(int j=i;j>=1;j--){
				if(mm-(a[i]-a[j])>=0){
					mm-=(a[i]-a[j]);
					sum++;
				}else{
					break;
				}
			}MAX=max(MAX,sum);
		}cout<<MAX;
	}
}
/*
5 8
-3 -1 2 2 7

*/
