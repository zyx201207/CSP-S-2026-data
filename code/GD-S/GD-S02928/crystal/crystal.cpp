#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],b[500010];
long long cha(long long g,long long p){
	long long s=1,l=m;
	for(int i=1;i<p;i++){
		if(abs(g-a[i])<=l){
			s+=1;
			l-=abs(g-a[i]);
		}
		
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		
	}
	sort(a+1,a+1+n);
	if(m==0){
		cout<<1;
		return 0;
	}
	if(abs(a[1]-a[2])==abs(a[3]-a[2])){
		long long cnt=0,i=1,l=0;
		while(l<=m){
			l=l+i*abs(a[1]-a[2]);
			i++;
			cnt+=1;
		}
		cout<<cnt;
		return 0;
	}
	long long v=s;
	v/=n;
	
	long long ans=0,cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=v){			
			
			cnt1=cha(a[i],i);
		}
		else{
			cnt2=cha(a[i],i);
		}
		ans=max(ans,max(cnt1,cnt2));
	}
	cout<<ans;
	return 0;
	
} 
