#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+5;
struct node{
	int cnt,l,r;
	char x;
}a[N],b[N];
int n,ans,L,i,j;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].cnt);
		cin>>a[i].x;
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+a[i].cnt-1;
		b[n-i+1]=a[i];L+=a[i].cnt;
//		cout<<a[i].l<<' '<<a[i].r<<'\n';
	}
	for(int i=1;i<=n;i++){
		b[n-i+1].l=L-b[n-i+1].l+1;
		b[n-i+1].r=L-b[n-i+1].r+1;
		swap(b[n-i+1].l,b[n-i+1].r);
	}
//	for(int i=1;i<=n;i++)cout<<b[i].l<<' '<<b[i].r<<'\n';
	for(i=1,j=1;a[i].r<=(L+1)/2;i++){
//		cout<<"FOR:"<<i<<'\n';
//			cout<<a[i].r<<' '<<b[j].l<<'\n';
		while(a[i].r>=b[j].l && j<=n){
//			cout<<"AT:"<<j<<'\n';
			if(a[i].x!=b[j].x){
//				cout<<"A:"<<i<<' '<<j<<'\n';
				ans+=min(b[j].r,a[i].r)-max(b[j].l,a[i].l)+1;
//				cout<<ans<<'\n'; 
			}
			if(b[j].r<=a[i].r)j++;
			else break;
//			cout<<a[i].r<<' '<<b[j].l<<'\n';
		}
	}
	if(a[i].l>(L+1)/2){
	cout<<ans;
	return 0;
	}
//		cout<<"FOR:"<<i<<'\n';
	while(a[i].r>=b[j].l && b[j].l<=(L+1)/2 && j<=n){
//			cout<<"AT:"<<j<<'\n';
		if(a[i].x!=b[j].x){
//			cout<<i<<' '<<j<<'\n';
			ans+=min(b[j].r,(L+1)/2)-max(b[j].l,a[i].l)+1;
		}
		if(b[j].r<=a[i].r)j++;
		else break;
	}
	cout<<ans;
	return 0;
}
