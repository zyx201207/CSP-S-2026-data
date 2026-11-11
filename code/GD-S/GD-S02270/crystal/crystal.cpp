#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N]; 
int cha[N];
int ans=0;
signed main(){
	ios::sync_with_stdio(0);
	
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
/*	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	
	} */
	int midnum=0;
	if(n%2==1){
		midnum=a[n/2];
	}else{
		midnum=a[n/2-1];
	}
		//cout<<midnum<<'\n';
//	cout<<m<<'\n'; 

	for(int i=0;i<n;i++){
		cha[i]=abs(midnum-a[i]);
		
	}
	sort(cha,cha+n);
	for(int i=0;i<n;i++){
		m-=cha[i];
		//cout<<cha[i]<<" "<<m<<'\n';
		if(m<0){
			break;
		} 
		ans++;
	}
	cout<<ans;
} 


