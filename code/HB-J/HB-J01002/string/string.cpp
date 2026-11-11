#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],k=0,ans=0,sum=0;;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(sum<1000000000){
			for(int j=1;j<=a[i];j++){
				s[k++]=c[i];
			}
		}
	}
	if(sum>=1000000000){
		cout<<sum/2;
		return 0;
	}
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
