#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n,len=0;
	LL a[200010];
	char c[200010];
	string str="";
	cin>>n;
	for(LL i=0;i<n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	LL cnt=0,l=0,r=len-1,p=0,q=n-1,mid=(l+r)/2;
	while(l<r&&p<=q){
		if(p==q&&l<=mid&&r>=mid){
			cnt+=min(mid-l,a[p]-mid);
			break;
		}
		else{
			if(a[p]==a[q]){
				if(c[p]!=c[q]) cnt+=a[p];
				l+=a[p]; r-=a[p];
				p++; q--;
			}
			else{
				if(a[p]>a[q]){
					if(c[p]!=c[q]) cnt+=a[q];
					a[p]-=a[q];
					l+=a[q];
					r-=a[q];
					q--;
				}
				else{
					if(c[p]!=c[q]) cnt+=a[p];
					a[q]-=a[p];
					l+=a[p];
					r-=a[p];
					p++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
