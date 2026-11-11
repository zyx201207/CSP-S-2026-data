#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1,ansd=0,num,xiabiao=0,miy=0;
	cin>>n>>m;
	int a[n+10]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(miy<=a[i]-a[i-1]){
			miy=a[i]-a[i-1];
			xiabiao=i;
		}
	}
	int k;
	if(n-xiabiao+1>xiabiao-1){
		k=xiabiao;
	}else{
		k=1;
	}
	
	for(int i=k+1;i<=n;i++){
		
		if(ansd!=0){
			if(a[i]==num) ansd++;
			else{
				cout<<max(ans,ansd);
				return 0;
			}
			continue;
		}
		
		if(m>(a[i]-a[i-1])*(i-k)){
			m-=((a[i]-a[i-1])*(i-k));
			ans++;
		}else{
			ansd=m/(a[i]-a[i-1])+1;
			num=a[i];
		}
	}
	cout<<max(ans,ansd);
	return 0;
} 
