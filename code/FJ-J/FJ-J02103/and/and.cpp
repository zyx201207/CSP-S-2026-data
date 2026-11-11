#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l;
	string s;
}a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i].l;
	if(m==1){
		long long maxx=a[0].l;
		for(int i=0;i<n;i++) maxx=max(maxx,a[i].l);
		cout<<maxx;//5·Ö 
		return 0;
	}
	for(int i=0;i<n;i++){
		int j=0;
		while(a[i].l>=1){
			a[i].s[j]=a[i].l%2-'0'+48;
			cout<<a[i].l%2-'0'+48<<endl;
			a[i].l/=2;
			j++;
		}
	}
	
	return 0;
}
