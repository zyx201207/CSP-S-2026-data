#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,len,a[N],ans;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		len+=a[i];
		cin>>s[i];
	}
	long long mid=len/2+len%2,num=0,l,r,cut;
	for(int i=1;i<=n;i++){

		if(num+a[i]>=mid){
			l=mid-num-len%2;
			r=num+a[i]-mid;
			cut=i;

			break;
		}
		num+=a[i];
	}
	for(int i=cut,j=cut;i>=1&&j<=n;){
		if(s[i]==s[j]){
			int k=min(l,r);
			l-=k;
			r-=k;
			if(l==0){
				i--;
				l=a[i];
			}
			if(r==0){
				j++;
				r=a[j];
			}
		}
		else{
			int k=min(l,r);
			l-=k;
			r-=k;
			ans+=k;
			if(l==0){
				i--;
				l=a[i];
			}
			if(r==0){
				j++;
				r=a[j];
			}
		}
	}
	cout<<ans;
	return 0;
}

