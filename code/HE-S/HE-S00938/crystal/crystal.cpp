#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int sum=0;
	cin>>n>>m;
	int a[500005]={},ans=-1,num;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int j=1;j<n;j++){
		sum=0;
		num=1;
		for(int i=j+1;i<n;i++){
			sum++;
			if(a[i]==a[i-1]){
				num++;
				continue;
			}
			if(m>=sum*(a[i]-a[i-1])){
				num++;
				m=m-(a[i]-a[i-1])*sum;
			}else{
				break;
			}
		}
		ans=max(ans,num);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
