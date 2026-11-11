#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	long long ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(sum%2==1){
		int j=sum-1;
		sum=(sum-1)/2;
		int i=0;
		while(sum--){
			if(s[i]!=s[j]){
				ans++;
			}
			i++;
			j--;
		}
	}else{
		int j=sum-1;
		sum/=2;
		int i=0;
		while(sum--){
			if(s[i]!=s[j]){
				ans++;
			}
			i++;
			j--;
		} 
	}
	cout<<ans;
	return 0;
}
