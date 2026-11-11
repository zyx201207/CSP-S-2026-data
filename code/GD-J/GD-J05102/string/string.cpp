#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	int a[250000];
	char b[250000];
	int n=0;
	long long s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n,ss=0;
	for(int q=1;1==1;q++){
		if(a[l]==0)l++;
		if(r==l)break;
		if(a[r]==0)r--;
		if(r==l)break;
		ss=min(a[l],a[r]);
		if(b[r]!=b[l]){
			s+=ss;
		}
		a[l]-=ss;
		a[r]-=ss;
	}
	cout<<s;
	return 0;
}
