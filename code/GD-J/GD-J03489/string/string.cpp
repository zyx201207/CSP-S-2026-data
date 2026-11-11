#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[210000];
char c[210000];
long long sum;
long long ans;
long long l,r;
long long i,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	i=1;
	l=1;
	j=n;
	r=sum;
	if(sum%2==0){
		while(l<r){
			//cout<<l<<" "<<r<<"\n";
			if(l+1==r){
				break;
			}
			long long ll=l,rr=r;
			long long ii=i,jj=j;
			if(a[i]==a[j]){
				l+=a[i];
				r-=a[j];
				i++;
				j--;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				l+=a[j];
				r-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				l+=a[i];
				r-=a[i];
				i++;
			}
			if(c[ii]!=c[jj]){
				ans+=l-ll;
				//cout<<ll<<" "<<l<<"  "<<rr<<" "<<r<<'\n';
			}
		}
//		if(c[i]!=c[j]){
//			ans++;
//		}
		cout<<ans;
	}else{
		while(l<r){
			long long ll=l,rr=r;
			long long ii=i,jj=j;
			if(a[i]==a[j]){
				l+=a[i];
				r-=a[j];
				i++;
				j--;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				l+=a[j];
				r-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				l+=a[i];
				r-=a[i];
				i++;
			}
			if(c[ii]!=c[jj]){
				ans+=l-ll;
				//cout<<ll<<" "<<l<<"  "<<rr<<" "<<r<<'\n';
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
1  6000000000
1000000001 5000000000
2000000001 4000000000
3000000001 3000000000

*/
