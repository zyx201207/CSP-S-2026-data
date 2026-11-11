#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans[300005];
int a[500005];
long long num[300005];
int s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		
//	}
//	int scus=n,scus2;
//	
	for(int i=n;i>=1;i--){
//		cout<<num[a[i]];
		if(num[a[i]]!=0){
			s[num[a[i]]-1]-=i;
			s[i]+=i;
		}
		num[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
//		cout<<s[i]<<" ";
		s[i]+=s[i+1];
//		cout<<s[i]<<" ";
		if(ans[a[i]]==0)
			ans[a[i]]+=i+s[i];
		
	}
//	cout<<endl;
//	for(int i=n;i>=scus;i--){
//		ans[a[i]]+=i;
//	}
//	for(int i=scus-1;i>=scus2;i--){
//		ans[a[i]]+=i-scus2;
////		cout<<a[i];
//	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

