#include <bits/stdc++.h>
using namespace std;
int s[1000005],a[1000005],b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string S;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
//		bool z=false;;
//		for(int j=1;j<=i;j++){
//			if(a[j]==a[i]){
//				b[j]+=a[i];
//				z=true;
//				break;
//			}
//		}
//		if(!z){
//			b[i]+=a[i];
//		}
		for(int j=1;j<=a[i];j++){
			S+=s[i];
		}
	}
	int ans;
	for(int i=1;i<=S.size();i++){
		if(S[i]!=S[n-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
