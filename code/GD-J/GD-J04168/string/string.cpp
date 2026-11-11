#include <bits/stdc++.h>
using namespace std;
int n;
long long sum,a[201000],ans,cnt,k,c[201000],p;
char b[200100],d[201000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>b[i]; 
		ans+=a[i];
	}
	ans=(ans+1)/2;
	for(int i=1; i<=n; i++){
		cnt+=a[i];
		if(cnt>=ans&&k==0){
			k=i;
			int gg=cnt-ans;
			c[++p]=a[i]-gg;
			d[p]=b[i];
			c[++p]=gg;
			d[p]=b[i];
		}
		else{
			c[++p]=a[i];
			d[p]=b[i];
		}
	}
	for(int i=1,j=p; i<=j; ){
		if(d[i]!=d[j]){
			if(c[i]>c[j]){
				sum+=c[j];
				c[i]-=c[j];
				c[j]=0;
				d[j]=d[i];
				j--;
			}
			else if(c[i]==c[j]){
				sum+=c[i];
				c[i]=0;
				c[j]=0;
				d[j]=d[i];
				i++;
				j--;
			}
			else{
				c[j]-=c[i];
				sum+=c[i];
				c[i]=0;
				d[i]=d[j];
				i++;
			}
		}
		else{
			if(c[i]==c[j]){
				c[i]=0;
				c[j]=0;
				i++;
				j--;
			}
			else if(c[i]>c[j]){
				c[i]-=c[j];
				c[j]=0;
				j--;
			}
			else{
				c[j]-=c[i];
				c[i]=0;
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}
