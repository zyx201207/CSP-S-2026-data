#include<bits/stdc++.h>
using namespace std;
int a[500005],b[200];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,tmp,ans=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	if(n<=5000){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					tmp=a[j];a[j]=a[j+1];a[j+1]=tmp;
				}
			}
		}
	}else{
		if(m<=100000000){
			for(int i=0;i<n;i++) b[a[i]+100]++;
			int poin=0;
				for(int j=-100;j<=100;j++) if(b[j+100]!=0)
				for(int i=0;i<b[j+100];i++) a[poin]=j;poin++;
		}
	}
	for(int i=1;i<n;i++){	
		if(a[i-1]==a[i]){
			ans++;continue;
		}
		m-=i*(a[i]-a[i-1]);
		if(m<0) break;
		ans++;        
	}
	cout<<ans;
	return 0;
}
