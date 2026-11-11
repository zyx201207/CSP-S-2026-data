#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,a[N];
char b[N];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	
	bool flag=1;//特判全相等 
	for(int i=1;i<=n;i++){
		if(b[i]!=b[i+1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	
	int k=n/2;//分半
	int l=1,r=n;//双指针
	for(int i=1;i<=k;i++){
		if(b[l]==b[r]){
			int p=min(a[l],a[r]);
			a[l]-=p;
			a[r]-=p;
		}
		l++,r--;
	}
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	ans/=2;
	cout<<ans; 
	return 0;
}
