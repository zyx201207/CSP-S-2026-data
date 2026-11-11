#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
long long m;
int n;
long long cry[500005];
int ans=0;

void fi(long long x){
	long long tot=m;
	int k=0;
	for(int i=n;i>0;i--){
		if(cry[i]>x)continue;
		else{
			tot-=x-cry[i];
			k++;
		}
		if(tot==0){
			ans=max(ans,k);
			cout<<ans<<' '<<k<<endl;
			break;
		}else if(tot<0){
			ans=max(ans,k-1);
			cout<<ans<<' '<<k-1<<endl;
			break;
		}
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>cry[i];}	
	sort(cry+1,cry+n+1);
	for(long long i=cry[n];i>=0;i--){
		fi(i);
		//cout<<i; 
		};
	cout<<ans<<endl;
	return 0;
}
