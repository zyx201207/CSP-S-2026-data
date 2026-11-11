#include<bits/stdc++.h>
#define ll long long
#define str string
const int N=2*1e5+10;
using namespace std;
ll n,a[N];
char c[N];
str s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	unsigned ll sum=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
	}
	unsigned ll mid;
	if(sum%2==1){
		mid=sum/2+1;
	}else{
		mid=sum/2;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=a[i]; j++){
			s+=c[i];
		}
	}
	unsigned ll ans=0;
	for(int i=0; i<mid; i++){
		if(s[i]!=s[sum-i-1]){
			ans++;
			//cout<<i<<endl;
		}
	}
	cout<<ans;
	return 0;
} 
