#include<bits/stdc++.h>
using namespace std;
int n;
string b[200005],s;
long long a[200005],ans,rem,sum = 0,idx;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j = 1;j<=a[i];j++) s+=b[i];
	}
	for(int i = 0,j = sum-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
