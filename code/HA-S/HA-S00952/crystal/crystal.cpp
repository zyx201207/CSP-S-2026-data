#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long n,m,sum=0,cnt=1,ma=1;
	cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=i;j>0;j--){
			if(a[j-1]>a[j]){
				int x=a[j-1];
				a[j-1]=a[j];
				a[j]=x;	
			}
			else{
				break;
			}	
		}
	}
	for(int i=0;i<n;i++){
		sum=0,cnt=1;
		for(int j=i;j>=1;j--){
			sum+=(a[j]-a[j-1]);
			if(sum>m){
				break;
			}
			else{
				cnt++;
			}
		}
		if(cnt>ma){
			ma=cnt;
		}
	}
	cout<<ma;
	return 0;
}
