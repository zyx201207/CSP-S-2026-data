#include<bits/stdc++.h>
using namespace std;

int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,jia=0;
	cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 	jia+=a[i];
	}
	jia=jia/n+1;
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(a[i]>jia){
			jia=i-1;
			break;
		}
	}
	long long sum=0,j=jia;
	for(int i=jia;i>0;i--){
		if((a[i]-a[i-1])<=(a[j+1]-a[i])){
			if(m>a[i]-a[i-1]){
			a[i-1]+=a[i]-a[i-1];
			m-=a[i]-a[i-1];
			sum++;
			}
		}else{
			if(m>a[j+1]-a[i]){
			a[i]+=a[j+1]-a[i];
			m-=a[j+1]-a[i];
			sum++;
			j++;
			}
		}
		if(m<=0)
		break;
	}
	cout<<sum;
	
	return 0;
}
