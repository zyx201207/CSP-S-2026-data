#include <bits/stdc++.h>
using namespace std;
const long long N=500010;
long long n,m,a[N];
long long min_(long long a,long long b){
	if (a<b){
		return a;
	}
	return b;
}
void solveB(){
	m/=(a[2]-a[1]);
	long long p=sqrt(m),tmp=0;
	if (m-p*p<p){
		tmp--;
	}
	cout<<2*p+1+tmp<<endl;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	//
	long long flagA=1,flagB=1,flag=0;
	for (long long i=1;i<min_(n,300)-10;i++){
		flag=1;
		if (a[i]!=i){
			flagA=0;
			break;
		}
		if (a[i+2]-a[i+1]!=a[i+1]-a[i]){
			flagB=0;
			break;
		}
	}
	if (flag&&(flagA||flagB)){
		solveB();
		return 0;
	}
	//
	long long ans=-1;
	for (long long i=1;i<=n;i++){
		long long mp1=0;
		for (long long l=1;l<=i;l++){
			mp1+=a[i]-a[l];
			if (mp1>m){
				break;
			}
			long long mp=mp1;
			long long r=i;
			for (;;){
				if (r>n){
					r=n;
					break;
				}
				if (mp+(a[r]-a[i])>m){
					r--;
					break;
				}
				r++;
				mp+=a[r]-a[i];
			}
			ans=max(ans,r-l+1);
			//cerr<<mp<<" "<<i<<" "<<l<<" "<<r<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
const long long N=501000;
long long n,m,a[N],prea[N],nxta[N];
long long lftm=0,rhtm=0;
long long l=1,r=1,ans=-1;
long long max_(long long a,long long b){
	if (a>b){
		return a;
	}
	return b;
}
long long curm(){
	return lftm+rhtm;
}
void r_inc(long long i){
	if (r==n){
		return;
	}
	while (a[r+1]-a[i]+curm()<=m){
		rhtm+=(a[r+1]-a[i]);
		r++;
		//cer<<"\nrhtmiii "<<rhtm<<" "<<r<<endl;
		if (r==n){
			return;
		}
	}
	return;
}
void rev_l(long long i){
	if (l==1){
		return;
	}
	while (a[i]-a[l-1]+curm()<=m){
		////cer<<"xfg2";
		lftm+=a[i]-a[l-1];
		l--;
		if (l==1){
			return;
		}
	}
	return;
}
long long main(){
	freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (long long i=1;i<=n;i++){
		if (r<i){
			r++;
		}
		if (i!=1){
			lftm+=(i-l)*(a[i]-a[i-1]);
			rhtm-=(r-i+1)*(a[i]-a[i-1]);
			//cer<<"*****"<<l<<" "<<r<<" "<<i<<endl;
		}
		if (curm()>m){
			lftm-=a[i]-a[l];
			l++;
		}
		r_inc(i);
		while (l<i&&r<n){
			if (a[r+1]-a[i]<a[i]-a[l]){
				rhtm+=(a[r+1]-a[i]);
				r++;
				lftm-=a[i]-a[l];
				l++;
			}
			else{
				break;
			}
		}
		//cer<<"rhtm2 "<<rhtm<<endl;
		r_inc(i);
		if (r==n){
			rev_l(i);
		}
		ans=max_(ans,r-l+1);
		//cer<<"\nDEBUG:curm="<<lftm<<" "<<rhtm<<" l="<<l<<" r="<<r<<" i="<<i<<endl;
	}
	cout<<ans<<endl;
	return 0;
}*/
