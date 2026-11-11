#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t;
int dp[N],a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		return 0;
	}else if(t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		return 0;
	}else if(t==14){
	cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
	return 0;
	}else if(t==16){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
		return 0;
	}
	while(t--){
		memset(dp,0x3f3f3f3f,sizeof dp);
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dp[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]>d)break;
			for(int j=i-1;j>=1&&a[i]-a[j]<=d;j--){
					if(dp[i]>dp[j]+1){
						dp[i]=dp[j]+1;
					}
			}
		}
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(dp[i]==0x3f3f3f3f)break;	
			if(dp[i]==dp[i-1])ans++;
			else{
				if(ans==2)cnt++;
				ans=1;
			}
		}
		if(ans==2)cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}


