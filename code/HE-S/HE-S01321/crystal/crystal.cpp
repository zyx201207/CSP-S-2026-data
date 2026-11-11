#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b,c[500005],d,sum,e[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e[i]=a[i];
	}
	for(int j=1;j<=n;j++){
		b+=a[j];
	}
	b/=n;
	for(int i=1;i<=n;i++){
		if (b>=a[i]){
			c[i]=b-a[i];
		}else{
			c[i]=a[i]-b;
		}
	}
	sort(c+1,c+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if (b>=a[i]){
			if (b-a[i]==c[1]){
				d=i;
				break;
			}
		}else{
			if (a[i]-b==c[1]){
				d=i;
				break;
			}
		}
	}
	for(int i=1;i<d;i++){
		if (m<0){
			break;
			sum--;
		}
		if (m==0){
			break;
		}
		a[i]+=a[d]-a[i];
		m-=a[d]-a[i];
		sum++;
		
	}
	for(int i=1;i<=n;i++){
		if (e[i]==a[d]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
