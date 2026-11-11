#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char carry[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans=0,cnt=0,s=0;
	long long h=-1;
	for(int i=0;i<n;i++){
		char c;
		cin>>a[i]>>c;
		for(int j=h+1;j<=h+a[i];j++){
			carry[j]=c;
		}
		h+=a[i];
		cnt+=a[i];
	}
	int k=(cnt+1)/2;
	for(int i=0;i<cnt;i++){
		if(i>=k){
			if(carry[cnt-i-1]!=carry[i]){
				ans++;
			}
		}
	}cout<<ans;
	return 0;
}
