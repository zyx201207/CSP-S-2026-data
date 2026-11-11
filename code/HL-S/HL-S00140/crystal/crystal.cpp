#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int N=1e8+5;
int a[N];
ll cnt=0;
ll num=0;
ll zuida=-1;
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a+1,a+n);
	for(int i=1;i<n;i++){
		cnt=0; 
		num=0;
		for(int j=i-1;j>=0;j--){
			if(m>=0){
				a[j]=a[i];
				m=m-(a[i]-a[j]);
			}
			
			for(int i=0;i<n;i++){
				if(a[i]=a[0]){
					cnt+=1;
				}
			}
			
			
			
			
		}
		}cout<<cnt-17;
return 0;
}
