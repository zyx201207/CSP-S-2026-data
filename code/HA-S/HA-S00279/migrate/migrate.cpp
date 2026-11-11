//3
#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000005],b[2000005];
long long aaa(int q,int l){
	if(d/q==1){
		return 0;
	}
	if(l<=d){
		return 0;
	}
	int t=d/q;
	return l-2*t+1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
		}
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		long long lst=b[2],l=1;
		for(int i=2;i<=n+1;i++){
			if(b[i]!=lst){
				sum+=aaa(lst,l);
				lst=b[i];
				l=1;
			}else{
				l++;
			}
		}
		cout<<sum;
	} 
	return 0;
}
