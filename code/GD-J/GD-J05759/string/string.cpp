#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,sum=0;
	cin>>n;
	int a[200005];
    char c,m[1000005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(int j=sum;j<sum+a[i];j++){
			m[j]=c;
		}
		sum+=a[i];
	}
	for(int i=0;i<sum/2;i++){
		if(m[i]!=m[sum-i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
