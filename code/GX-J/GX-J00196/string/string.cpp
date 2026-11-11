#include <bits/stdc++.h>
using namespace std;
int n,l,ans=0;
string sum;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int sl;
		string a;
		
		cin>>sl>>a;
		for(int j=1;j<=sl;j++){
			sum[++l]=a[0];
		}
	}
	for(int i=1;i<=l;i++){
		if(sum[i]!=sum[l+1-i]){
			sum[i]=sum[l+1-i];
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}

