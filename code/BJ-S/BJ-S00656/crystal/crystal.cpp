#include<bits/stdc++.h>
using  namespace std;
long long n,m,a[500005],sum=1,b,a1[500005],mina;
bool q=1;
int main(){
	a[0]=-10000000000000;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long amin=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
		if(b!=a[i]){
			q=0;
		}
	}
	if(q){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		a1[i]=a[i+1]-a[i];
		if(amin>a1[i]){
			amin=a1[i];
			mina=i;
		}
	}
	int mid=mina,l=1,r=1;
	while(m>=0){
		if(abs(a[mid]-a[mid-l])<=abs(a[mid+r]-a[mid])*sum&&abs(a[mid]-a[mid-l])<=m&&mid-l>0){
			m-=abs(a[mid]-a[mid-l]);
			sum++;
			l++;
			//cout<<1<<' ';
		}
		else if(abs(a[mid]-a[mid-l])>abs(a[mid+r]-a[mid])*sum&&abs(a[mid+r]-a[mid])*sum<=m&&mid+r<=n){
			m-=abs(a[mid+r]-a[mid])*sum;
			sum++;
			mid++;
			l++;
			//cout<<2<<' ';
		}
		else if(mid-l<=0&&abs(a[mid+r]-a[mid])*sum<=m&&mid+r<=n){
			m-=abs(a[mid+r]-a[mid])*sum;
			sum++;
			mid++;
			l++;
			//cout<<3<<' ';
		}
		else if(mid+r<=n&&abs(a[mid]-a[mid-l])<=m&&mid-l>0){
			m-=abs(a[mid]-a[mid-l]);
			sum++;
			l++;
			//cout<<4<<' ';
		}
		else{
			break;
		}
		//cout<<m<<' ';
	}
	//cout<<222;
	cout<<sum;
	return 0;
}
