#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5;
int a[N];int n,m;int k;
int sum=0;



bool check(int h1,int h2){
	int sm=0;
	for(int i=h1;i<=h2;i++){
		sm+=a[h2]-a[i];
	}
	if((h2-h1)*a[h2]-sm>m)return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
//	cout<<n<<m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	/*sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=l+r/2;
		int mid1=(mid+l)/2,mid2=mid+r/2;;
		if(check(mid1,mid2)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
		k=l-1;
	}
	/*/
	sum/=n;
	for(int i=1;i<=n;i++){
		a[i]=abs(a[i]-sum);
	}
	sort(a+1,a+n+1);
	
	
	while(m>=0){
		if(m-a[k]<=0){
			break;
		}
		if(k==n){
			break;
		}
		k++;
		m-=a[k];
		
	}

	cout<<k;

	return 0;
} 

