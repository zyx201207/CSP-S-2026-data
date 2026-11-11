#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200001];
	cin>>n>>m;
	bool yes=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4){
			yes=false;
		}
	}
	if(n==1){
		long long max=0;
		for(long long i=1;i<=n-1;i+=2){
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max;
	}else if(n==2){
		sort(a+1,a+n+1);
		for(long long i=n;i>=1;i--){
			if(a[i]==a[i-1]){
				cout<<a[i];
				return 0;
			}
		}
		int max=0;
		for(int i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(max<=(a[i]&a[j])){
					max=a[i]&a[j];
			}
		}
		cout<<max;
	}
	}else if(m==n){
		long long c=0;
		for(long long i=1;i<=n-1;i+=2){
			c+=a[i]&a[i+1];
		}
		cout<<c;
	}else if(m==n){
		long long c=0;
		for(long long i=1;i<=n-1;i+=2){
			c+=a[i]&a[i+1];
		}
		cout<<c;
	}else if(n-1==m){
		long long c=0;
		for(long long i=1;i<=n-1;i+=2){
			c+=a[i]&a[i+1];
		}
		long long max=0;
		for(long long i=1;i<=n;i++){
			if((c^a[i])>max){
				max=(c^a[i]);
			}
		}
		cout<<max;
	}else if(yes==true){
		long long s1,s2,s3,s4;
		for(long long i=1;i<=n;i++){
			if(a[i]==1){
				s1++;
			}else if(a[i]==2){
				s2++;
			}else if(a[i]==3){
				s3++;
			}else{
				s4++;
			}
		}
		if(s4>=m){
			cout<<4;
		}else if(s3>=m){
			cout<<3;
		}else if(s2>=m){
			cout<<2;
		}else if(s2+s3>=m){
			cout<<2;
		}else if(s1>=1){
			cout<<1;
		}else if(s1+s3>=m){
			cout<<1;
		}else cout<<0;
	}
	return 0;
}

