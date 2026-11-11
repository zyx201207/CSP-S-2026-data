#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum;
int a[2000005],o=0,d=0;
char b[20000005];
string c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
		c=c+b[i];	
		}
		sum=sum+a[i];
	}
			for(int i=0;i<n;i++){
		if(b[i]==b[i+1]){
			o++;
		}
	}
	if(o==n-1){
		cout<<0;
		return 0;
	}
if(n==1){
		cout<<0;
		return 0;
	}
	if(sum%2==1){
		for(int i=0;i<sum/2+1;i++){
			if(i!=sum/2+1){
				if(c[i]!=c[sum-i-1]){
			d++;
			}
			}
		
	}
	}else{
			for(int i=0;i<sum/2;i++){
				if(c[i]!=c[sum-i]){
			d++;
			}
		
	}
	}
	cout<<d;
	return 0;
}
