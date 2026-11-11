#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
const int maxn=5e5+2;

int n,m;
int arr[maxn];
int b[maxn];	


int cheak(int x,int y){
	
	memset(b,0,sizeof(b));
//	cout<<"y : "<<y<<endl;
	for(int i=1;i<=y;i++){
		b[i]=abs(x-arr[i]);
//		cout<<x<<' '<<arr[i]<<endl;
	}
//	cout<<endl;
	sort(b+1,b+y+1);
//	for(int i=1;i<=y;i++){
//		cout<<b[i]<<' ';
//	}
//	cout<<endl;
	int sum=0,ax=0;
	for(int i=1;i<=y;i++){
		
		sum+=b[i];
		ax++;
		if(sum>m){
			ax--;
			break;
		}	
	
	}
	return ax;
	
}

signed main(){
	
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		
		cin>>arr[i];
		
	}
	
	sort(arr+1,arr+n+1);
	int ans=-1;
	for(int i=1;i<=n;i++){
//		cout<<cheak(arr[i],i)<<' ';
		ans=max(ans,cheak(arr[i],i));
	}
//	cout<<endl;
	cout<<ans<<endl;
		
	return 0;
	
}
/*

5 8
2 7 -3 -1 2
*/
