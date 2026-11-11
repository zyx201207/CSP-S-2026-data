#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l;
	char c;
}a[200005],b[100005];
long long n,sum=0;
int fid(int l,int u,bool f){
	int c;
	if(f)for(int i=u;a[i-1].l<=l;i++)c=i;
	else for(int i=u;a[i-1].l<=l;i++)c=i;
	return c;
}int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=0,last_l2=0,i1=0,i2=0;
	for(long long i=0;i<n;i++){
		cin>>a[i].l>>a[i].c;
		if(a[i].c==a[i-1].c)a[i-1].l+=a[i].l,n--,i--;		
	}for(int i=0;i<n;i++)if(i!=0)a[i].l+=a[i-1].l;
	for(int i=0;i<n;i++){
		b[n-i-1].l=a[i].l;
		b[n-i-1].c=a[i].c;
	}if(n==1){
		cout<<0;
		return 0;
	}for(int i=0;l<=a[n-1].l/2;){
		if(a[i1].c!=b[i2].c)sum+=min(a[i1].l,b[i2].l)-l;
		l=min(a[i1].l,b[i2].l);
		++l;
		i1=fid(l,i,1),i2=fid(l,last_l2,0),last_l2=i2,i=i1;
	}cout<<sum;
}
