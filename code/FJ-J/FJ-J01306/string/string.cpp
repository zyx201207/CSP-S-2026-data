#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int a[100000005];
char c[50];
bool flag=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	string S;
	int k=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			S[k]=c[i];
			k++;
		}
	}
	for(long long i=1;i<=n;i++){
		if(i!=1&&c[i]!=c[i-1]){
			flag=false;
		}	
	}
	if(flag){
		cout<<"0";
		return 0;
	}
	else{
		for(long long i=1,j=k/2;i<=k,j>=1;i++,j--){
			if(S[i]!=S[j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}