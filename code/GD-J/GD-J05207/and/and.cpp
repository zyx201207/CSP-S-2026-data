#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cout<<0;
			return 0;
		}
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		sort(a+1,a+1+n);
		ans=a[2]&a[3];
		for(int i=4;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==3){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					ans=max(ans,a[i1]&a[i2]&a[i3]);
				}
			}
		}
		cout<<ans;
		return 0;
	}else if(m==4){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]);
					
				}
			}
		}
		cout<<ans;
		return 0;
	}else if(m==5){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]);
					
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}else{
		sort(a+1,a+1+n);
		cout<<a[m];
		return 0;
	}
	
	return 0;
}
