#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long l=0,l2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		l+=b[i];
	}
	l/=2;
	int i2=1;
	bool g=1;
	
	for(int i=1;i<=n;i++){
		if(l2+b[i]>l && g==1){
			a[i2]=b[i]-(l2+b[i]-l);
			i2++;
			g=0;
			a[i2]=b[i]-a[i2-1];
		}
		a[i2]=b[i];
		l2+=b[i];
		i2++;
	}
	i2--;

	
	long long ans=0;
	long long k=i2;
	
	for(int i=1;i<k;){
		long long mn=min(a[i],a[k]);
		long long mx=max(a[i],a[k]);
		if(c[i]!=c[k]){
			//cout<<111;
			
			ans+=mn;
			if(a[i]>a[k]){
				a[i]-=a[k];
				k--;
			}else{
				a[n-k+1]-=a[i];
				i++;
			}
		}else if(a[i]!=a[k]&&(k-i!=1)){
			ans+=mx-mn;
			i++;
			k--;
		}else{
			i++;
			k--;
		}
		
	}
	cout<<ans;
	return 0;
}
