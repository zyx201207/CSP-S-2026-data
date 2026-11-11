#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500000];
int n,ans1=0,ans2=0,p,p1;
long long m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(ans<m){
				ans+=a[j]-a[i];
				p=a[j]-a[i];
				p1=a[j];
				ans1++;
				ans2=max(ans1,ans2);
			}else{
				ans-=p;
				ans1--;
			}
		}
		ans=0;
		ans1=0;
	}
	cout<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
