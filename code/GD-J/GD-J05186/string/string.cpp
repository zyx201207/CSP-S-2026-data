#include<bits/stdc++.h>
using namespace std;
int n,ans=0,m=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[2000005];
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int num,c1;
		char c;
		cin>>num>>c;
		for(int j=0;j<num;j++){
			a[j+m]=c;
		}
		m+=num;
	}
	for(int i=0,j=m-1;i<=(m-1)/2,j>=(m-1)/2;i++,j--){
		if(a[i]!=a[j]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

