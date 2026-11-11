#include <bits/stdc++.h>
using namespace std;
int a[5000005];
string s[5000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string y;
		cin>>x>>y;
		a[i]=x;
		s[i]=y;
	}
	int l=1,r=n;
	int p=0,f=0;
	while(l<=r){
		if(s[l]!=s[r]){
			if(p+min(a[l],a[r])>=1000000000){
				f++;
				p=(p+min(a[l],a[r]))%1000000000;
			}
			p+=min(a[l],a[r]);
		} 
		if(a[l]<a[r]){
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else if(a[l]==a[r]){
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
		else{
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	if(f==0){
		cout<<p;
		return 0;
	}
	int pp=p,ppp=0;
	while(pp){
		pp/=10;
		ppp++;
	}
	cout<<f;
	if(p==1000000000) {p=0;ppp=0;}
	for(int i=1;i<=9-ppp;i++){
		cout<<0;
	}
	if(p!=0) cout<<p;
 	return 0;
}
