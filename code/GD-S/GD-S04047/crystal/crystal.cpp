#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],f=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int k=1;k<=n;k++){
		cin>>a[k];
	}
	for(int k=3;k<=n;k++){
		if(a[k]-a[k-1]!=a[k-1]-a[k-2]){
			f=0;
			break;
		}
	}
	if(f){
		long long x=abs(a[2]-a[1]);
		m=min(n,m/x);
		cout<<m;
	}
	else{
		sort(a+1,a+n+1);
		for(int k=1;k<=n;k++){
			long long i=k-1,j=k-1,t=m,sum=1;
			while(i>=1&&j<=n){
				if(t<a[k]-a[i]&&t<a[j]-a[k])break;
				if(abs(a[k]-a[i])>abs(a[j]-a[k])){
					t=t-abs(a[j]-a[k]);
					j++;
					sum++;
				}
				else if(abs(a[k]-a[i])==abs(a[j]-a[k])){
					t=t-abs(a[j]-a[k]);
					i--;
					j++;
					sum++;
				}
				else{
					t=t-abs(a[k]-a[i]);
					i--;
					sum++;
				}
			}
			while(i>=1){
				if(t<abs(a[k]-a[i]))break;
				t=t-abs(a[k]-a[i]);
				i--;
				sum++;
			}
			while(j<=n){
				if(t<abs(a[j]-a[k]))break;
				t=t-abs(a[j]-a[k]);
				j++;
				sum++;
			}cout<<sum<<endl;
			ans=max(ans,sum);
		}
		cout<<ans;
	}
} 
