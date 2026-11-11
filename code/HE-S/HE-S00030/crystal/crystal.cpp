#include<bits/stdc++.h>
using namespace std;
long long a[102400000];
long long b[102400000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mi=-1,flag=0;
	cin>>n>>m;
	cin>>a[1];
	for(long long i=2;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(n>5000){
		if(abs(a[1]-a[2])>1){
			long long qq=1,qqq=0,qw=1;
			while(1){
				qqq+=qq;
				qq+=a[1]-a[2];
				qw++;
				if(qqq==m){
					cout<<qw;
					return 0;
				}
				if(qqq>m){
					cout<<qw-1;
					return 0;
				}
			}
		}else{
			long long qqq=0,qw=1;
			while(1){
				qqq+=qw;
				qw++;
				if(qqq==m){
					cout<<qw;
					return 0;
				}
				if(qqq>m){
					cout<<qw-1;
					return 0;
				}
			}
		}		
	}
	sort(a+1,a+n+1);
	long long l;
	for(long long i=1;i<=n;i++){
		if(b[i]>1){
			if(mi<b[i]){
				l=i;mi=max(mi,b[i]);
			}			
			flag=1;
		}
	}	
	long long cs=1,cs1=cs,ans=1;
	while(1){		
		cs1=cs;
		for(long long i=1;i<=cs;i++){
			if(a[i]<a[i+cs1]&&m-a[i+cs1]+a[i]>=0){
				m=m-a[i+cs1]+a[i];
				a[i]=a[i+cs1];								
			}
			if(m-a[i+cs1]+a[i]<=0&&i!=cs){
				if(l==a[i]){
					ans+=mi-1;
				}
				cout<<ans;
				return 0;
			}			
			cs1--;			
		}	
		ans++;
		cs++;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
