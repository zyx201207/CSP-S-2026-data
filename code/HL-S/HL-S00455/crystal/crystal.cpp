#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long num[205];
long long s[205];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int ans=0;
	cin>>n>>m;
	long long m0=m;
	int c=0;
	bool absm=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(abs(a[i])>100) absm=1; 
		if(i>=3){
			if(i==3){
				if(a[3]-a[2]==a[2]-a[1]) c=a[3]-a[2];
			} 
			else{
				if(c!=a[i]-a[i-1]) c=-1;
			}
		}	
	}
	sort(a+1,a+n+1);
	int i=1;
	if(c!=-1&&c!=0){
		while(m>=0){
			m-=((i-1)*(a[i]-a[i-1]));
			i++;
			ans++;
		}
		if(m<0) ans--;
		cout<<ans;
	}
	else if(n<=5000){
		int ttans=0;
		for(int t=1;t<n;t++){
			int i=t;
			while(m>=0&&i<=n){
				m-=((i-t)*(a[i]-a[i-1]));
				i++;
				ans++;
			}
			if(m<0) ans--;
			ttans=max(ttans,ans);
			ans=0;
			m=m0;
		}
		cout<<ttans;	
	}
	else if(absm==0&&n>5000){
		for(int i=1;i<=n;i++){
			num[a[i]+101]++;
		}
		s[0]=0;
		s[1]=num[1];
		for(int i=2;i<=201;i++){
			s[i]=s[i-1]+num[i];
		}
		int ttans=0;
		for(int i=0;i<=201;i++){
			
			int j=i;
			while(m>=0&&j<201){
				m-=(s[j]-s[i]);
				j++;
				ans=s[j]-s[i];
			}
			if(m<0) ans--;
			ttans=max(ttans,ans);
			ans=0;
			m=m0;
		}
		cout<<ttans;
	}	
}