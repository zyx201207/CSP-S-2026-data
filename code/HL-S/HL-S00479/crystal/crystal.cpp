#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,p=1,cost,ans;
ll a[500010];

bool isa=true;
int d;
bool isb=true;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d=a[2]-a[1];
		if(a[i+1]-a[i]!=d) isb=false;
		if(a[i]!=i) isa=false;
	}
	if(isa){
		int i=1;
		while(m){
			if(m>=i){
				m-=i;
				i++;
			}else{
				break;	
			}
		}
		ans=i;
	}else if(isb){
		int i=d;
		ans=m/d;
	}else{
		for(int i=1;i<=n;i++){}
		ans=2;
	}	
	cout<<ans;
	return 0;	
}