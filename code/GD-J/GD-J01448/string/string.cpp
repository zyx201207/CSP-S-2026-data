#include<bits/stdc++.h>
using namespace std;
int n;
int sum,ans;
int a;	
char x;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>x;
		for(int j=sum;j<sum+a;j++){
			b[j]=x;
			cout<<b[j];
		}
		sum+=a;
	}
	if(sum%2==0){
		ans=sum/2;
	}else{
		ans=sum/2+1;
	}
	sum=ans;
	for(int i=0;i<sum;i++){
		if(b[i]==b[sum-i-1]){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
