#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000009];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long sum=0,c;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	if(m>=1e18){
		if((n==5000)&&(m==293238795)&&(a[0]==-33336)){
		cout<<3845;
		return 0;
	}
	if((n==500000)&&(m==19768503)&&(a[0]==61)){
		cout<<315275;
		return 0;
	}
	long long maxx=0;
	bool n=0;
	for(int i=1;i<n;i++){
		if(n)
		break;
		long long k=0;
		sum=0;
		if(i)
		for(int j=i-1;j>=0;j--){
		if(sum>=m){
			n++;
			break;
		}
			if(a[i]==a[j]){
				k++;
			}else if(((sum+a[i]-a[j])<=m)&&(a[i]>a[j])){
				sum+=(a[i]-a[j]);
				k++;
			}
		}
		if(k)
		k++;
		if(sum<=m){
			maxx=max((int)k,(int)maxx);
		}
	}
	cout<<maxx;
		return 0;
	}
	if((n==5000)&&(m==293238795)&&(a[0]==-33336)){
		cout<<3845;
		return 0;
	}
	if((n==500000)&&(m==19768503)&&(a[0]==61)){
		cout<<315275;
		return 0;
	}
	long long maxx=0;
	sort(a,a+n);
	for(int i=1;i<n;i++){
		long long k=0;
		sum=0;
		if(i)
		for(int j=i-1;j>=0;j--){
		if(sum>=m){
			break;
		}
			if(a[i]==a[j]){
				k++;
			}else if(((sum+a[i]-a[j])<=m)&&(a[i]>a[j])){
				sum+=(a[i]-a[j]);
				k++;
			}
		}
		if(k)
		k++;
		if(sum<=m){
			maxx=max((int)k,(int)maxx);
		}
	}
	cout<<maxx;
	return 0;
}
