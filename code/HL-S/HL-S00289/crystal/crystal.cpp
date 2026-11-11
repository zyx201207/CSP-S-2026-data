#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
//int k=0xc0c0c0c0;
int ans=-9999;
int a[N];
int n,m,tmp1,tmp;
int s[N];
int ping;
//int e=0;
//cishu:shengyucishu sum:shuijings huliang
int f(int cishu,int sum){
	//cout<<cishu<<" "<<endl;
	if(sum>=ans){
		ans=sum;
	}
	if(ans>ping) return ping-1;
	if(cishu<=0) return ans;
	//ans=sum;
	if(ans>sum) return ans;
	//cout<<ans<<"        "<<sum<<endl;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			//for(int z=1;z<=cishu;z++){
				//e++;
			tmp=a[j]-a[i];
			if(tmp>cishu) return 0;
			else a[i]+=tmp;
			//}
			if(a[i]==a[j]){
				tmp1+=1;
			}
			//ans=max(ans,dfs(cishu-1,sum+1));
		}	
	}
	f(cishu-tmp,sum+tmp1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];	
	}
	//cout<<s[n]<<endl;
	ping=s[n]/n;
	//cout<<ping<<endl;
	//cout<<ping<<endl;
	//for(int i=1;i<=n;i++){
	//	cout<<s[i]<<" ";
	//}
	sort(a+1,a+n+1);
	if(a[n]-a[n-1]==a[2]-a[1] && a[3]-a[2]==a[n]-a[n-1] ){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=2;k<=100;k+=2){
					if(a[2]-a[1]==a[n]-a[n-1]){
						if(m<(a[n]-a[n-1])){
							cout<<0;
							break;
						}else if(m==(a[n]-a[n-1])){
							cout<<1;
							break;
						}else{
							if((a[n]-a[n-1])%2==0){
								cout<<(m%(a[n]-a[n-1]));
								break;
							}else if((a[n]-a[n-1])%2==1){
								if(m%k*(a[n]-a[n-1])==0){
									cout<<(m%(a[n]-a[n-1]))-1;
									break;
								}else{
									cout<<(m%(a[n]-a[n-1]));
									break;
								}
							}else{
								cout<<m%(a[n]-a[n-1]);
								break;
							}	
						}	
					}
				}
			}	
		}
	}
	else{
		int r=f(m,0);
		cout<<r;
	}
	//cout<<r<<""<<e;
	//cout<<ans;
	//sort(a+1,a+1+n);
	//int i=1;
	//while(m!=0){
		//if(a[i]<a[i+1]){
			//while(a[i]==a[i+1]){
				//a[i]=a[i]+1;
				//m--;
			//}
		//}
		//while()
	//}	
	return 0;
}
