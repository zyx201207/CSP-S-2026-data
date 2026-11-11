#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    long long n,m,mm=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	cout<<(a[1]&a[2])<<endl;
	if(m==1){
		long long ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}else if(m==2){
		long long ma=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout<<ma;
	}else if(m==n){
		long long ma=-1;
		for(int i=1;i<=n;i++){
			ma=(ma&a[i]);
		}
		cout<<ma;
	}else if(m==n-1){
		long long ma=0,k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				ma=max(ma,(a[i]&a[j]));
			}
			k=max(ma,k);
		}
		cout<<ma;
	}else if(mm<4){
		long long a1=0,a2=0,a3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				a1++;
			}
			if(a[i]==2){
				a2++;
			}
			if(a[i]==3){
				a3++;
			}
		}
		m-=a3;
		if(m<=a2){
			cout<<2;
		}else if(m<=a1){
			cout<<1;
		}else {
			cout<<0;
		}
	}else{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	
	
    return 0;
}

