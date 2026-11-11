#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],cnt,ans=0,tot,dp[200005]={0},mcnt=0;
bool k[200005][31],f[200005];
int maxx;
bool com(int a,int b){
	return a>b;
}
int main()
{
	memset(k,0,sizeof(k));
	memset(f,0,sizeof(f));
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n,com);
	sort(b+1,b+1+n,com);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n;i++){
		cnt=0;
		while(b[i]>0){
			mcnt=max(cnt,mcnt);
			k[i][cnt]=b[i]&1;
			b[i]>>=1;
			//cout<<k[i][cnt];
			cnt++;
		}
	}
	
	int p=mcnt,ll=0;
	tot=0;
	//cout<<endl;
	while(p>=0){
		ll=0;
		for(int i=1;i<=n;i++){
			if(k[i][p]){
				ll++;
			}
		}
		if(ll<m){
			//cout<<ll<<"ll"<<endl;
			p--;
			continue;
		}else{
			for(int i=1;i<=n;i++){
				if(k[i][p]&&!f[i]){
					f[i]=true;
					tot++;
				}
			}
		}
		p--;
	}
	int kk=0;
	//cout<<f[1];
	for(int i=1;i<=n;i++){
		if(f[i]){
			ans=a[i];
			f[i]=!f[i];
			break;
		}
	}
	//cout<<ans;
	//cout<<endl;
	//for(int i=1;i<=n;i++)cout<<f[i]<<" ";
	//cout<<endl;
	kk=1;
	for(int i=1;i<=n&&kk<m;i++){
		if(f[i]){
			ans&=a[i];
			//cout<<endl<<"lol:"<<a[i]<<endl;
			kk++;
		}
	}
	//cout<<mcnt;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
