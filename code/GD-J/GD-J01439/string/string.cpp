#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
struct zfc{
	ll k;
	char c; 
}a[N];
ll sum,ans;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
		sum+=a[i].k;
	}
	ll js=0,mid=sum/2+sum%2,id=0;
	for(int i=1;i<=n;i++){
		js+=a[i].k;
		if(js>=mid){
			int t=js-mid;
			a[i].k-=t;
			for(int j=n;j>=i;j--) a[j+1]=a[j];
			n++;
			a[i+1].k=t;
			a[i+1].c=a[i].c;
			if(sum%2) a[i].k--;
			id=i;
			break;
		}
	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<a[i].k<<' '<<a[i].c<<"\n";
//	}
//	cout<<"\n";
	for(int i=id,j=id+1;i>=1,j<=n;){
		if(a[i].c!=a[j].c){
			ans+=min(a[i].k,a[j].k);
//			cout<<i<<' '<<j<<' '<<ans<<"\n";
		}
		if(a[i].k>a[j].k){
			a[i].k-=a[j].k;
			j++;
		}
		else if(a[i].k==a[j].k){
			i--;
			j++;
		}
		else{
			a[j].k-=a[i].k;
			i--;
		}
	}
	cout<<ans;

	return 0;
}

