#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],Max=-1e18,Min=1e18,diff; 

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool b=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
		Min=min(Min,a[i]);
	}
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<"\n"; 
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			b=0;
			break;
		}
	}
//	cout<<1;
	if(b){
		diff=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if((diff+a[i]-a[1])*(i-1)/2>m){
				cout<<i-1;
				break;
			}
		}
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=i-1,r=i+1,sum=1,cnt=0;
			while(cnt<m){
				while(a[l]>a[i]&&l>=1) l--;
				while(a[r]>a[i]&&r<=n) r++;
				int diff1=abs(a[l]-a[i]),diff2=abs(a[r]-a[i]);
				if(l<1&&r>n){
//					cout<<"aaaa\n";
//					cout<<l<<" "<<r<<"\n";
					break;
				}
//				cout<<diff1<<" "<<diff2<<"\n";
				if(diff1<=diff2){
					sum++;
					if(l>=1){
						cnt+=diff1;
//						cout<<a[l]<<" ";
						l--;
					} 
					else{
						cnt+=diff2;
//						cout<<a[r]<<" ";
						r++;
					} 
				}
				else{
					sum++;
					if(r<=n){
						cnt+=diff2;
//						cout<<a[r]<<" ";
						r++;
					}
					else{
						cnt+=diff1;
//						cout<<a[l]<<" ";
						l--;
					}
				}
//				cout<<"\n";
//				cout<<"\n"<<cnt<<"\n";
			}
//			cout<<"\n";
			if(cnt>m) sum--;
//			cout<<l<<" "<<r<<"\n"; 
//			cout<<i<<" "<<sum<<"\n";
			if(sum>ans){
//				cout<<i<<" "<<cnt<<" "<<sum<<"\n";
//				cout<<l<<" "<<r<<"\n\n";
				ans=sum;
			}
		}
		cout<<ans;
	}
	return 0;
}
