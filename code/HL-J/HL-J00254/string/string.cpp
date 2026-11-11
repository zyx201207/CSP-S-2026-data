#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int a[N];
char s[N];
string s1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	if(n==1) cout<<0;
	else if(n==2){
		if(a[1]>a[2]){
			cout<<a[1];
		}else{
			cout<<a[2];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s1+=s[i];
			}	
		}
		int k=s1.size();
		int mid=k/2;
		int ans=mid+1;
		for(int i=1;i<=mid;i++){
			for(int j=k;j>mid;j--){
				if(s1[i]==s1[j]){
					ans--;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
