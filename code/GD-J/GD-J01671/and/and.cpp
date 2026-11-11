#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int s=0;
		for(int i=1;i<=n;i++){
			int d;
			cin>>d;
			s=max(s,d);
		}
		cout<<s;
	}
	else if(m==2){
		int s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
	}
	else if(m==n-1){
		int s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int d=a[1];
			if(i!=1){
				for(int j=2;j<=n;j++){
					if(j!=i){
						d=d&a[j];
					}
				}
			}
			else{
				d=a[2];
				for(int j=3;j<=n;j++){
					d=d&a[j];
				}
			}
			s=max(s,d);
		}
		cout<<s;
	}
	else if(m==n){
		int d;
		cin>>d;
		int s=d;
		for(int i=2;i<=n;i++){
			cin>>d;
			s=s&d;
		}
		cout<<s;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=0;i<=n-m;i++){
			int s=a[n];
			for(int j=n-1-i;j>=n-m+1-i;j--){
				s=s&a[j];
			}
			ans=max(s,ans);
			if(a[n-m+1-i]<=ans){
				break;
			}
		}
		cout<<ans;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
