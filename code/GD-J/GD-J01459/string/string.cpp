#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
long long sum,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long l=0;
	while(l<=sum/2){
		l++;
		long long j=0,x=l;
		long long r=sum/2+(sum/2-l) ;
		while(x>0){
			j++;
			x-=a[j];
		}
		long long k=0,y=r;
		while(y>0){
			k++;
			y-=a[k];
		}
		if(c[j]!=c[k]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
