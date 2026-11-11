#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[200005];
long long n;
string c[2000005];
string st;
long long len;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			st+=c[i];
		}
	}
	int sum=0;
	len=st.size();
	for(int i=0;i<=len;i++){
		if(st[len-i]==st[i]){
			continue;
		}else{
			st[len-i]=st[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}