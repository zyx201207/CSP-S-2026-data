#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool bin[50];
struct node{
	long long val,key;
}num[200005];
long long mp(int a,int p){
	long long ans=a;
	for(int i=1;i<=p-1;i++) ans*=a;
	return ans;
}
void zh(int a){
	for(int i=30;i>=0;i--){
		if(a-mp(2,i)>0) bin[i]=1,a-=mp(2,i);
		else bin[i]=0;
	}
}
void js(int a,int i){
	num[i].val=a;
	for(int j=30;j>=0;j--){
		if(a-mp(2,i)>0) a-=mp(2,j);
		else {
			if(bin[j]!=0) num[i].key+=mp(2,j); 
		}
	}
}
bool cmp(node a , node b){
	return a.key>b.key;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	//--------------------------------------
	if(m==2){
		sort(a+1,a+1+n);
		bool b=0;
		for(int i=n;i>=1;i--){
			if(a[i]==a[i-1]){
				b=1;
				cout<<a[i];
				return 0;
			}
		}
		int mx=-1,ans;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				mx=max(ans,mx);
			}
		}
		cout<<mx;
		return 0;
	}
	//---------------------------------------
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}cout<<ans;
		return 0;
	}
	//---------------------------------------
	int ans;
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n;i>=n-m+1;i--) ans&= a[i];
	cout<<ans;
	return 0;
}
