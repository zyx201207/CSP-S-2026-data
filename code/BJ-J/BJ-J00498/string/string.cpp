#include<bits/stdc++.h>
using namespace std;
char a[500010],a2[500010],a3[500020],a4[500020];
long long a1[500020];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n,sum=0;
	cin>>n;

	for(int i=1;i<=n;i++){
		char x;
		cin>>a1[i]>>x;
		
		for(int j=sum+1;j<=sum+a1[i];j++){
			a[j]=x;
		}
		sum+=a1[i];
	}
		for(int i=1;i<=sum/2;i++){
			a2[i]=a[i];
			
		}
		int su=1;
		for(int i=(sum+1)/2+1;i<=sum;i++){
			a3[su]=a[i];
			
			su++;
			
		}
		int cnt=1;
		for(int i=sum/2;i>=1;i--){
			a4[cnt]=a3[i];
			cnt++;
		}
	
	
	long long ans=0;
	for(int i=1;i<=sum/2;i++){
		if(a2[i]!=a4[i]){
			ans++;
		}
		
	}
	cout<<ans;
	return 0;
}
