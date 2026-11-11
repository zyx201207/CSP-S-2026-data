#include<bits/stdc++.h>
using namespace std;
long long n,len,tmp,l,r,ans;
char ch;
map<long long,int>mp;
struct dt{
	long long l,r;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len>>ch;
		a[i].l=tmp+1,a[i].r=tmp+len,a[i].c=ch;
		tmp+=len;
	}
	for(int i=1;i<=n;i++){
		if(a[i].l<=(tmp+1)/2&&(tmp+1)/2<=a[i].r){
			for(int j=0;j<i;j++) a[j]=a[j+1];
			a[i-1].l=a[i].l,a[i-1].r=tmp/2,a[i-1].c=a[i].c,a[i].l=(tmp+1)/2+1,l=i-1,r=i;
			if(a[i-1].r<a[i-1].l) l--;
			if(a[i].r<a[i].l) r++;
		}
	}
	while(l>=0&&r<=n){
		if(a[l].r-a[l].l+1>a[r].r-a[r].l+1){
			if(a[l].c!=a[r].c) ans=ans+a[r].r-a[r].l+1;
			a[l].r=a[l].r-a[r].r+a[r].l-1,r++;
		}else if(a[l].r-a[l].l+1<a[r].r-a[r].l+1){
			if(a[l].c!=a[r].c) ans=ans+a[l].r-a[l].l+1;
			a[r].l=a[r].l-a[l].r+a[l].l-1,l--;
		}else{
			if(a[l].c!=a[r].c) ans=ans+a[r].r-a[r].l+1;
			l--,r++;
		}
	}
	cout<<ans;
	return 0;
}

