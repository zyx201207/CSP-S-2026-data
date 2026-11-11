#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005],x,cnt[200005],cnt2[200005],k,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=a[i];
		cnt[i]=0;
		//for(int j=1;j<=40;j++){
			//b[j]=0;
		//}
		while(x>0){
			b[++cnt[i]]=x%2;
			x/=2;
			
		}
		k=max(k,cnt[i]);
		for(int j=1;j<=cnt[i];j++){
		///	cout<<j<<" "<<b[j]<<endl;
			cnt2[j]+=b[j];
		}
	}
//	cout<<1<<endl;
	for(int i=k;i>=1;i--){
	//		cout<<endl;
		if(cnt2[i]>=m){
		//	cout<<i<<endl;
			ans+=(1<<(i-1));
			for(int j=1;j<=k;j++){
				cnt2[j]=0;
			}
		for(int j=1;j<=n;j++){
				if((a[j]&(1<<(i-1)))!=0){
					x=a[j];
					cnt[j]=0;
				//	for(int k2=1;k2<=40;k2++){
					//	b[k2]=0;
				//	}
					while(x>0){
						b[++cnt[j]]=x%2;
						x/=2;
			
					}
	//	k=max(k,cnt[i]);
					for(int k2=1;k2<=cnt[j];k2++){
							//cout<<j<<" "<<b[j]<<" "<<a[j]<<endl;
						cnt2[k2]+=b[k2];
					}
				}else{
					a[j]=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
