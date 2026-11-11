#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,ans=1,sum=0;
	char b;
	cin>>n;
	string c;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=ans;j<=ans+a;j++){
			c[j]=b;
			
		}
		ans+=a;
	}
	for(int i=1;i<=ans;i++){
		if(c[i]==c[ans+1-i]){
			sum=sum;
		}else
			sum++;
	}
	cout<<sum/2<<c;
}
