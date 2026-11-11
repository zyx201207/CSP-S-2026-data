#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200005];
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}	
	if(m==1){
		cout<<*(max_element(a+1,a+n+1));
	}else if(m==2){
		long long mx=-1;
		for(long long i=1;i<=n;++i){
			for(long long j=i+1;j<=n;++j){
				long long x=a[i]&a[j];
				mx=max(x,mx);
			}
		}
		cout<<mx;
	}else{
		sort(a+1,a+n+1);
		long long mx1;
		for(long long i=n;i>1;--i){
			if(a[i]==a[i-1]){
				mx1=a[i];
				break;
			}
		}
		long long cnt=0,mx2=pow(2,31)-1;
		for(long long i=n;cnt<m;--i){
			mx2&=a[i];
			cnt++;
		}
		cout<<max(mx1,mx2);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
