#include<bits/stdc++.h>
using namespace std;
long long int n,sum,ans;
long long int a[10000005];
 char c[1000005];
 char w[1000005];

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=sum;j<sum+a[i];j++){
			w[j]=c[i];
		}
		sum+=a[i];
	}
	if(sum%2!=0){
		int r=(sum-1)/2;
		for(int i=0;i<=r;i++){
			if(w[i]!=w[sum-1-i])
				ans++;
		}
	}
	else{
		int r=sum/2-1;
		for(int i=0;i<=r;i++){
			if(w[i]!=w[sum-1-i])
				ans++;
		}
	}
	cout<<ans;
}

