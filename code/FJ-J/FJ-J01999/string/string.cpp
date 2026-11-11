#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	long long l,r;
}a[200005];
int tmp=0;
long long lens,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		lens+=x;
		if(i>1&&y==a[tmp].c){
			a[tmp].r+=x;
			continue ;
		}
		tmp++;
		a[tmp].c=y;
		if(tmp==1){
			a[tmp].l=1;
			a[tmp].r=x;
		}
		else{
			a[tmp].l=a[tmp-1].r+1;
			a[tmp].r=a[tmp-1].r+x;
		}
	}
	if(tmp==1){
		cout<<0;
		return 0;
	}
	long long mid=lens/2;
	long long g=0,x,y;
	int i=1,z,j;
	if(lens%2==1){
		mid++;
		for(i;i<=tmp;i++){
			g+=a[i].r-a[i].l+1;
			if(g>=mid)break;
		}
		if(mid-a[i].l-(a[i].r-mid)>=0)ans+=mid-a[i].l-(a[i].r-mid);
		else ans+=(a[i].r-mid)-(mid-a[i].l);
		a[i-1].r=min(a[i].l,mid*2-a[i].r)-1;
		a[i+1].l=max(a[i].r,mid*2-a[i].l)+1;
		z=i+1;j=i-1;
		while(a[z].l>a[z].r){
			a[z+1].l=a[z].r;
			z++;
		}
		while(a[j].r<a[j].l){
			a[j-1].r=a[j].l;
			j--;
		}
	}
	else{
		mid--;
		for(i;i<=tmp;i++){
			g+=a[i].r-a[i].l+1;
			if(g>=mid)break;
		}
		if(g==mid){
			z=i+1,j=i;
		}
		else{
			ans+=abs(mid-a[i].l-(a[i].r-mid));
			a[i-1].r=min(a[i].l,mid*2-a[i].r)-1;
			a[i+1].l=max(a[i].r,mid*2-a[i].l)+1;
			z=i+1,j=i-1;
			while(a[z].l>a[z].r){
				a[z+1].l=a[z].r;
				z++;
			}
			while(a[j].r<a[j].l){
				a[j-1].r=a[j].l;
				j--;
			}
		}
	}
	while(j>=1,z<=tmp){
		if(a[j].r-a[j].l+1<a[z].r-a[z].l+1){
			if(a[j].c!=a[z].c)ans+=a[j].r-a[j].l+1;
			j--;
			a[z].l+=a[j].r-a[j].l+1;
		}else if(a[j].r-a[j].l+1>a[z].r-a[z].l+1){
			if(a[j].c!=a[z].c)ans+=a[z].r-a[z].l+1;	
			z++;
			a[z].r-=a[z].r-a[z].l+1;
		}else {
			if(a[j].c!=a[z].c)ans+=a[z].r-a[z].l+1;	
			j--,z++;
		}
		while(a[z].l>a[z].r){
			a[z+1].l=a[z].r;
			z++;
		}
		while(a[j].r<a[j].l){
			a[j-1].r=a[j].l;
			j--;
		}
	}
	cout<<ans;
	return 0;
}

