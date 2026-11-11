#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool bpl[N];
long long a[N];
long long nw[N];
long long nw2[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	bool flag=true;
	long long mx=-38758;
	long long mn=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=false;
		}
	}
	for(int i=1;i<=n;i++){
		bpl[i]=false;
	}
	int ans=0;

	sort(a,a+n+1);
	long long cnt=1;
	long long cs=0;	
	if(flag==true){
		cout<<1;
		return 0;
	}
	if(a[n]-a[n-1]>=2){
		cout<<n-1;
		return 0;
	}
	else{
		long long tmp=0;
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]==1){
				cnt+=1;
			}
			if(a[i+1]-a[i]>=2){
				cs+=i-tmp;
				tmp=i;
			}
		}
	}
	if(cnt<=m){
		cout<<cs;
	}
	else{
		cout<<0;
	}
	return 0;
} 

