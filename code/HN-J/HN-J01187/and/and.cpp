//my only hope is it can get full or not 
#include<bits/stdc++.h>
using namespace std;
int a[200005][31],ch[200005],l[200005],n,m,p[32],cnt;
long long ans,l1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(ch,0,sizeof(ch));
	cin>>n>>m;
	p[1]=1;
	for(int i=2;i<=31;i++)p[i]=p[i-1]*2;
	ans=p[31]-1;
	for(int i=1;i<=n;i++){
		cin>>l1;
		l[i]=l1;
		for(int j=30;j>=1;j--){
			if(l1>=p[j]){
				l1-=p[j];
				a[i][j]=1;
			}
		}
	}
	for(int i=30;i>=1;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
				cnt++;
				ch[j]=1;
			}
			if(cnt>=m)break;
		}
		
		if(cnt>=m)break;
		for(int i=1;i<=n;i++)ch[i]=0;
	}
	if(cnt<m){
		cout<<0<<endl;
		return 0;
	}
	if(cnt>=m){
		for(int i=1;i<=n;i++){
			if(ch[i]==1){
				cout<<ans<<endl;
				ans&=l[i];
			}
		}
	}
	if(cnt==m){
		cout<<ans<<endl;
		return 0;
	}
	int ccnt=ans;
	ans=p[31]-1;
	if(cnt>=m){
		for(int i=30;i>=1;i--){
			cnt=0;
			for(int j=1;j<=n;j++){
				if(ch[j]==1){
					cnt++;
					ch[j]==2; 
				} 
			}	
			if(cnt==m)break;
			for(int i=1;i<=n;i++){
				if(ch[i]==2)ch[i]=1;
			} 
		}
		if(cnt==m){
			for(int i=1;i<=n;i++){
				if(ch[i]==2){
					ans&=l[i];
				}
			}
			cout<<ans<<endl;
			return 0;
		}else{
			cout<<ccnt<<endl;
			return 0;
		}
	}
	return 0;
}
