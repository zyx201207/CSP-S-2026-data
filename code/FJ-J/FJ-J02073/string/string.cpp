#include<bits/stdc++.h>
using namespace std;
char c[200010],s[200010];
long long a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j<sum+a[i];j++){
			s[j]=c[i];
		}
		sum+=a[i];
	}
	long long x=0;
	for(int i=1;i<=ans/2;i++){
		if(s[i]==s[ans-i+1]){
			x=x;
		}else{
			x++;
		}
	}
	cout<<x;
	return 0;
} 
