#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005],ans;
char c[200005],d[200055];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}	
	for(int i=1,j=1;i<=n;){
		if(a[i]>=b[j]){
			if(c[i]!=d[j])ans+=b[j];
			a[i]-=b[j];j++;
		}else {
			if(c[i]!=d[j])ans+=a[i];
			b[j]-=a[i];i++;
		}
	}
	cout<<ans/2<<"\n";
	return 0;
}
