#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+100;
long long n,ans=0;
long long m;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool A=true,B=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=false;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3){
			B=false;
		}
	}
	if(A){
		for(int i=1;i;i++){
			if(i*(i+1)/2>=m){
				cout<<i+1;
				return 0;
			}
		}
	}
	if(B){
		int k=a[2]-a[1];
			m/=k;
			for(int i=1;i;i++){
				if(i*(i+1)/2>=m){
					cout<<i+1;
					return 0;
				}
			}
		}
	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long prize=0;
		long long cnt=0;
		for(int j=i;j>=1;j--){
			prize+=a[i]-a[j];
			if(prize>m){
				break;
			}else{
				cnt++;
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
} 
