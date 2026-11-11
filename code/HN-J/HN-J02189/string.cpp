# include<bits/stdc++.h>
using namespace std;
int const N=1e7;
struct ll{
	long long sl,hj;
	char id;
}a[N];
long long n;
long long zh,jk;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long r,l;
	for(int i=0;i<n;i++){
		cin>>a[i].sl>>a[i].id;
		jk+=a[i].sl;
		a[i].hj=jk;
	}
	if(jk%2==1){
		r=n/2+1;
		l=n/2-1;
	}else{
		l=n/2;
		r=n/2+1;
	}
	long long p,o;
	for(int i=0;i<n/2;i++){
		p=a[i].sl-a[50-1-i].sl;
	}
	if(p>0){
		for(int i=n;i>n/2;i++){
			a[i+1]=a[i];
		}
		a[r].id=a[n/2].id;
		a[r].sl=a[n/2].sl-p;
		a[n/2].sl-p;
	}else{
		for(int i=n/2;i>0;i++){
			a[i+1]=a[i];
		}
		a[l].id=a[n/2].id;
		a[l].sl=a[n/2].sl-p;
		a[n/2].sl+p;	
	}
	for(int i=0;i<n/2;i++){
		if(a[l].id==a[i].id){
			if(a[l].sl>a[r].sl){
				a[l].sl-=a[r].sl;
				r+1;
			}else if(a[l].sl<a[r].sl){
				a[l].sl-=a[r].sl;
				l-1;
			}
		}else{
			if(a[l].sl>a[r].sl){
				a[l].sl-=a[r].sl;
				zh+=a[r].sl;
				r+1;
			}else if(a[l].sl<a[r].sl){
				a[l].sl-=a[r].sl;
				zh+=a[l].sl;
				l-1;
			}
		}
	}
	cout<<zh;
	return 0;
}
