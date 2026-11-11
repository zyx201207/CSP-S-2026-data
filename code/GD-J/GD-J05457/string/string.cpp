#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,sum=0,mid;
	cin>>n;
	a=' '+a;
	char s;
	for(int i=1;i<=n;i++){
		cin>>x>>s;
		sum+=x;
		while(x--){
			a+=s;
		}
	}
	string a1="",b1="";
	mid=sum/2;
	if(sum%2==1){
		for(long long i=1;i<=mid;i++) a1+=a[i];
		for(long long i=mid+2;i<=sum;i++) b1+=a[i];
	}else{
		for(long long i=1;i<=mid;i++) a1+=a[i];
		for(long long i=mid+1;i<=sum;i++) b1+=a[i];
	}
	long long ans=0;
	for(int i=0;i<mid;i++){
		if(a1[i]!=b1[mid-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
