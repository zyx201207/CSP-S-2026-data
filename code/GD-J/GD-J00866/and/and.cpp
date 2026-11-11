#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,a[200002],mx;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("t.txt","w",stdout);
	cin>>n>>m;
	if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];if(i>1)a[i]&=a[i-1];
		}cout<<a[n];
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(m==2){int id;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>mx){
				mx=a[i];id=i;
			}
		}
		int mxx=0;
		for(int i=1;i<=n;i++){
			if(i!=id)mxx=max(mxx,mx&a[i]);
		}
		cout<<mxx;
	}
	else{bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];if(a[i]!=i-1)f=0;
		}
		if(f){
			int k=0,t=n;while(t>0){
				k++;t/=2;
			}if(m>k)cout<<0;
			else{int t2=1;for(int i=1;i<=k-m;i++)t2*=2;
				int ans=0;for(int i=k-m+1;i<k;i++){
					ans+=t2;t2*=2;
				}cout<<ans;
			}
			
		}
		else{
			sort(a+1,a+n+1);int ans=a[n];
			for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
			cout<<ans;
		}
	}
	
	
	return 0;
} 
