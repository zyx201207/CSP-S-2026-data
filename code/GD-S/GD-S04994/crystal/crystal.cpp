#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long num[N];int n,m;long long qi[N];long long no=m,ans=0,la=0,lo=0;
bool che(int no,int la){
	long long bj=num[no]*(no-la);
	long long js=qi[no-1]-qi[max(la-1,0)];
	long long da=bj-js;
	if(da>m)return 0;
	return 1;
}
bool A,B;
long long cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>num[i];
		if(num[i]!=i)A=1;
		if(i==2){
			cha=num[i]-num[i-1];
		}
		if(i>2&&(num[i]-num[i-1]!=cha)){
			B=1;
		}
	}
	for(int i = 1;i<=n;i++){
		qi[i]=qi[i-1]+num[i];
	} 
	sort(num+1,num+1+n);
	if(n<=5000){
		no=m,ans=0,la=0,lo=0;
		for(int i = 1;i<=n;i++){
			no=m;
			for(int j = i-1;j>=1;j--){
				if(no<(num[i]-num[j])){
					ans = max(1ll*(i-j),ans);
					break;
				}
				if(j==1){
					ans = max(1ll*i,ans);
				}
				no-=(num[i]-num[j]);
				
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(!A){
		int mid,l=0,r=n-1,ans=1;//ans:答案长度(不算最后一个，所以要+1) 
		while(l<=r){
			mid=((l+r)>>1);
			if((((mid+1)*mid)>>1)<=m){
				ans = max(ans,mid+1);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}

	if(!B){
		int mid,l=0,r=n-1,ans=1;//ans:答案长度(不算最后一个，所以要+1) 
		while(l<=r){
			mid=((l+r)>>1);
			if((((mid+1)*mid)>>1)*cha<=m){
				ans = max(ans,mid+1);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	no=m,ans=0,la=0,lo=0;
	for(int i = 1;i<=n;i++){
		if(num[i]-num[i-1]>m){
			ans = max(ans,1ll);
			continue;
		}
		long long mid,l=1,r=i,ou=i;
		while(l<=r){
			mid=((l+r)>>1);
			if(che(i,mid)){
				ou=min(ou,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans = max(i+1-ou,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
