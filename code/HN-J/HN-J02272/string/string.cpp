#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char b[200010];
long long x,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		x+=a[i];
	}
	long long l=1,ry=a[j];
	int i=1,j=n;
	while(l<=x/2){
		l+=a[i];
		long long k=a[i];
		if(a[i]<=ry){
			if(b[i]!=b[j])ans+=a[i];
			ry-=a[i];
			if(ry==0){
				j--;
				ry=a[j];
			}
		}
		else{
			if(b[i]!=b[j])ans+=ry;
			k-=ry;
			j--;
			while(k>a[j]){
				if(b[i]!=b[j])ans+=a[j];
				k-=a[j];j--;
			}
			if(b[i]!=b[j])ans+=k;
			ry=a[j]-k;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
