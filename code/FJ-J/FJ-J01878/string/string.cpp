#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0,js=0;
	string ans,b;
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>a>>b;
		js+=a;
		for(int j=1;j<=a;j++){
			ans+=b;
		}
	}
		for(int i=1;i<=js/2;i++){
			if(ans[js-i+1]!=ans[i]){
				sum++;
				ans[js-i+1]=ans[i];
			}
		}
	cout<<sum;
}
