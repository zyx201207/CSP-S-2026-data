#include<bits/stdc++.h>
using namespace std;
int a[200020],dp[200010];
int cnt=0;int n,m;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ma=0;
		if(m==1){
			for(int i=1;i<=n;i++){
				ma=max(ma,a[i]);
			}
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int i1=1;i1<=n;i1++){
					if(i!=i1)
					ma=max(ma,a[i]&a[i1]);
			}
			}
		}else if(m==3){
			for(int i=1;i<=n;i++){
				for(int i1=1;i1<=n;i1++){
					for(int i2=1;i2<=n;i2++){
					if(i!=i1&&i!=i2&&i1!=i2)
					ma=max(ma,a[i]&a[i1]&a[i2]);
			}
			}
			}
		}else if(m==4){
			for(int i=1;i<=n;i++){
				for(int i1=1;i1<=n;i1++){
					for(int i2=1;i2<=n;i2++){
						for(int i3=1;i3<=n;i3++)
						if(i!=i1&&i!=i2&&i1!=i2&&i!=i3&&i1!=i3&&i2!=i3)
					ma=max(ma,a[i]&a[i1]&a[i2]&a[i3]);
			}
			}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==1){int ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(a[i],ma);
		}
		cout<<ma;
		return 0;
	}
	if(m==n){
		
	for(int i=1;i<=n;i++){
			cin>>a[i];
		}int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
				for(int i1=1;i1<=n;i1++){
					if(i!=i1)
					ma=max(ma,a[i]&a[i1]);
			}
			}
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n;i>=2;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if((n&(n-1))==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<1<<endl;
		return 0;
	}
	int me=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		me=max(me,a[i]);
		
	}
	
	if(me<4){
		int x1=0,x=0,x2=0,x3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				x++;
			}
			if(a[i]==1){
				x1++;
			}
			if(a[i]==2){
				x2++;
			}
			if(a[i]==3){
				x3++;
			}
		}
		if(m<=x3){
			cout<<3;
			return 0;
		}else if(m<=x2){
			cout<<2;
			return 0;
		}else if(m<=1||m<=3+1){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
			
			
		
	}
	sort(a+1,a+n+1);
	int ans111=a[n];
	for(int i=n;i>=1;i++){ans111&=a[i];
		if(!m){
			cout<<ans111;
		}
		m--;
		
		
	}
	return 0;
}
