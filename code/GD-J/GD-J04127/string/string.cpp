#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int sum;char c;
}a[200005];
bool cmp(node a,node b){
	return a.sum>b.sum;
}
int n,maxa=-1,maa=-1,num=0,ii;
char ch;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
		num+=a[i].sum;
	}
	if(n==1){
		cout<<0;return 0;
	}
	if(n==2){
		if(a[1].c!=a[2].c)
		cout<<min(a[1].sum,a[2].sum);
		else cout<<0;
		return 0;
	}
	int fff=0;
	for(int i=1;i<=n;i++){
		if(a[1].c!=a[i].c) fff++;
	}
	if(fff==0){cout<<0;return 0;} 
	for(int i=1;i<=n;i++){
		maxa=max(maxa,a[i].sum);
		if(maxa!=maa){
			ii=i;
			maa=maxa;
			ch=a[i].c;
		}
	}
	num-=maxa;
	for(int i=1;i<=n;i++){
		if(a[i].c==ch&&i!=ii){
			num-=a[i].sum;
		}
	}
	cout<<num;
}

