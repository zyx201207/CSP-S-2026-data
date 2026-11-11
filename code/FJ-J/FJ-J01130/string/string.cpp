#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct e{
	int l;
	int r;
	char c;
}a[200005];
string s;
signed main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	int last=0,sum=0;
	for(int i=1;i<=n;i++){
		int a1;char c;
		cin>>a1>>c;
		a[i].l=last;a[i].r=last+a1-1;
		a[i].c=c;
		sum+=a1;
		last+=a1;
	}
	int midd=sum/2;int middi=0;
	int l=1,r=n;
	//for(int i=1;i<=n;i++)cout<<a[i].l<<" "<<a[i].r<<a[i].c<<endl;

	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].l<=midd&&a[mid].r>=midd){
			middi=mid;
			break;
		}
		else if(a[mid].l>midd)r=mid-1;
		else l=mid+1;
	}
//	cout<<middi;//middi=2,midd=3,sum=5,n=3

	for(int i=1;i<=middi;i++){
		for(int j=a[i].l;j<=min(sum%2?midd:midd-1,a[i].r);j++){
				s[j]=a[i].c;
			s[sum-j-1]=a[i].c;
			
		}
	}

	for(int i=middi;i<=n;i++){
		for(int j=max(a[i].l,midd);j<=a[i].r;j++){
			if(s[j]!=a[i].c){
				ans++;
			}
		}
	} 
	cout<<ans;	
	return 0;
	}
	//ºÃÄÑ>_< 
	
