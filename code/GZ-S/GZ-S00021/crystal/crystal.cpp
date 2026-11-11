//GZ-S00021 观山湖区外国语实验中学 陶昊冉 
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500005]={0};
	long long m; 
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans = 0,ccont =0;
	for(int i = 0;i<n-1;i++){
		ans=a[i+1]-a[i];
		if(ans==0) {
			a[i+1]=+a[i];
			ccont++;
		}
		else if(m-abs(ans)>0||m-abs(ans)==0){
			m-=ans;
			a[i+1]+=a[i+1];
			ccont++;
		}
		else break;
	}
	cout<<ccont;
	return 0;
} 
