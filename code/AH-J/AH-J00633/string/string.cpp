#include<bits/stdc++.h>
using namespace std;
struct node{
	int l;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].s;
		m+=a[i].l;
	}
	m/=2;
	int si=0,sj=0;
	long long ans=0;
	for(int i=1,j=n;si<=m&&sj<=m&&i<j;){
		if(a[i].l>a[j].l){
			if(a[i].s!=a[j].s){
				ans+=a[j].l;
			}
			sj+=a[j].l;
			a[i].l-=a[j].l;
			a[j].l=0;
			j--;
		}
		if(a[i].l==a[j].l){
			if(a[i].s!=a[j].s){
				ans+=a[j].l;
			}
			si+=a[i].l;
			sj+=a[j].l;
			a[i].l=a[j].l=0;
			i++,j--;
		}
		if(a[i].l<a[j].l){
			if(a[i].s!=a[j].s){
				ans+=a[i].l;
			}
			si+=a[i].l;
			a[j].l-=a[i].l;
			a[i].l=0;
			i++;
		}
	}
	cout<<ans;
	return 0;
}

