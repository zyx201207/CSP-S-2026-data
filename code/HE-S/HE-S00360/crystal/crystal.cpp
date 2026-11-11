#include <bits/stdc++.h>
using namespace std;
long long n,m,end,t;
long long a[500005],s[500005];
long long cha(long l,long r){
	int cc=s[l+1]-s[l];
	for(int i=l;i<=r;i++){
		if(s[i+1]-s[i]!=cc){
			return 0;
		}
	}
	return cc;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]<0){
		for(int i=2;i<=n;i++){
			a[i]+=-a[1];
			a[i]++;
		}
		a[1]=1;
	}
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
		if(m>=s[i-1]&&m<s[i]){
			end=i;
			break;
		}
	}
	long long cha1=s[end]-s[end-1];
	for(int i=end-1;i>0;i--){
		if(!cha(i-1,end)){
			t=cha1-(s[i]-s[i-1]);
			for(int j=i;j<=end;j++){
				s[j]+=t;
			}
			
			m-=t;
			if(m<=0)break;
		}
	}
	long long ans=0,ansj=0;
	long long chaa=s[1]-s[0];
	for(int i=1;i<=n;i++){
		if(s[i]-s[i-1]==chaa||a[i]==a[i-1]){
			ans++;
		}
		else{
			ansj=max(ansj,ans);
			ans=0;
			chaa=s[i]-s[i-1];
		}
	}
	ansj=max(ansj,ans);
	cout<<ansj;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
