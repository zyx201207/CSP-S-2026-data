#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l;
	char ch;
}a[200005];
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].l>>a[i].ch;
	}
	long long ans=0;
	for(int i=0,j=n-1;i<j;){
		if(a[i].l>a[j].l){
			if(a[i].ch!=a[j].ch)ans+=a[j].l;
			a[i].l-=a[j].l,j--;
		}
		else if(a[i].l<a[j].l){
			if(a[i].ch!=a[j].ch)ans+=a[i].l;
			a[j].l-=a[i].l,i++;
		}
		else{
			if(a[i].ch!=a[j].ch)ans+=a[i].l;
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
