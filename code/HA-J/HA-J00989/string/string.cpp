#include<bits/stdc++.h>
using namespace std;
char c[200010];
long long n,a[200010],sum,p,q,m,k=1,l,r,ans;
bool f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[1]){
			sum++;
		}
	}
	if(sum==n){
		cout<<0;
		return 0;
	}
	sum=0;
	for(int i=1;i<=n;i++){
		if(c[i]==c[n-i+1]&&a[i]==a[n-i+1]){
			sum++;
		}
	}
	if(sum==n){
		cout<<0;
		return 0;
	}
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(sum%2==1){
		p=sum/2+1;
		while(p-a[k]>0){
			p-=a[k];
			k++;
		}
		q=a[k]-p;
		m=p-1;
		if(m>q){
			a[k]=m-q;
			f=1;
		}else{
			a[k]=q-m;
		}
		if(f==0){
			l=k-1;
			r=k;
		}else{
			l=k;
			r=k+1;
		}
		while(l>0&&r<n+1){
			if(c[l]==c[r]){
				if(a[l]>a[r]){
					a[l]-=a[r];
					a[r]=0;
					r++;
				}else{
					a[r]-=a[l];
					a[l]=0;
					l--;
				}
			}else{
				if(a[l]>a[r]){
					a[l]-=a[r];
					ans+=a[r];
					a[r]=0;
					r++;
				}else{
					a[r]-=a[l];
					ans+=a[l];
					a[l]=0;
					l--;
				}
			}
		}
	}else{
		p=sum/2;
		while(p-a[k]>0){
			p-=a[k];
			k++;
		}
		q=a[k]-p;
		m=p-1;
		if(m>=q){
			a[k]=m-q+1;
			f=1;
		}else if(m<q&&m!=0){
			a[k]=q-m+1;
		}else if(m<q&&m==0){
			a[k]-=2;
		}
		if(f==0){
			l=k-1;
			r=k;
		}else{
			l=k;
			r=k+1;
		}
		while(l>0&&r<n+1){
			if(c[l]==c[r]){
				if(a[l]>a[r]){
					a[l]-=a[r];
					a[r]=0;
					r++;
				}else{
					a[r]-=a[l];
					a[l]=0;
					l--;
				}
			}else{
				if(a[l]>a[r]){
					a[l]-=a[r];
					ans+=a[r];
					a[r]=0;
					r++;
				}else{
					a[r]-=a[l];
					ans+=a[l];
					a[l]=0;
					l--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

