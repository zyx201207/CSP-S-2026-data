#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char b[N];
long long ans;
int tot;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	tot=n;
	for(int i=1;i<=tot;i++){
		int tmp=a[i];
		long long k=0;
		for(int j=tot;j>=1;j--){
			if(tmp>=a[j]) tmp-=a[j];
			else{
				a[j]-=tmp;
				tot=j;
				if(b[i]!=b[j]) k+=tmp;
				break;
			} 
			if(b[i]!=b[j]) k+=a[j];
		}
		ans+=k;
	}
	cout<<ans;
	return 0;
} 
