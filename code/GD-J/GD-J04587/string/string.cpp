#include<cstdio>
#include<iostream>
using namespace std;
int n;
long long ans=0;
const int maxn=200000;
int a[maxn];
char s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int l=0,r=n-1;
	while(l<r){
		if(a[l]>a[r]){
			a[l]-=a[r];
			if(s[l]!=s[r]){ans+=a[r];}
			r--;
		}
		else if(a[r]>a[l]){
			a[r]-=a[l];
			if(s[l]!=s[r]){ans+=a[l];}
			l++;
		}
		else{
			if(s[l]!=s[r]){ans+=a[l];}
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
