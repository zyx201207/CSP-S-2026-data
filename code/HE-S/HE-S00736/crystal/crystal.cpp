#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[5000001],b[5000001],q,cnt,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			cnt++;
		}
	}
	sort(a+1,a+n+1);
	long long mins=1e18;
	for(int i=1;i<=n;i++){
		int s=a[i],sum=0;
		for(int j=1;j<=n;j++){
			if(a[j]<s){
			sum+=s-abs(a[j]);
			}		
		}
		if(sum<=m && sum<mins){
			mins=sum;
			p=s;
		}
	}
	for(int i=1;i<=n;i++){
		if(p>a[i]) {
			q++;
			b[q]=p-a[i];
		}
	}
	sort(b+1,b+q+1);
	for(int i=1;i<=q;i++){
		if(m<=0) break;
		cnt++;
		m-=b[i];
	}
	cout<<cnt;
	return 0;
}
