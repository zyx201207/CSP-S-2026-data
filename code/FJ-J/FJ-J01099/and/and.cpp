#include <cstdio>
#include <iostream>
using namespace std;
int a[2003],t[105000],bxnum[32],bynum[32],ansnum[32];
void c_b(int s,int bsnum[32]){
	for(int i=1;i<=30;i++){
		bsnum[i]=s%2; s/=2;
	}
	return;
}
void andans(){
	for(int i=1;i<=30;i++) if(bxnum[i]==1 && bynum[i]==1) ansnum[i]=1;
	return; 
}
int b_c(){
	int sum=0,cnt=1;
	for(int i=1;i<=30;i++){
		sum+=ansnum[i]*cnt;
		cnt*=2;
	}
	return sum;
}
void clean(int bsnum[32]){
	for(int i=1;i<=30;i++) bsnum[i]=0;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	if(m==1){
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x>ans) ans=x;
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(t[x]==0){
				t[x]=1;
				a[++cnt]=x;
			}
		}
		for(int i=1;i<cnt;i++){
			for(int j=i+1;j<=cnt;j++){
				c_b(a[i],bxnum);
				c_b(a[j],bynum);
				andans();
				int s=b_c();
				if(s>ans) ans=s;
				clean(bxnum);
				clean(bynum);
				clean(ansnum);
			}
		}
		cout<<ans;
	}
	return 0;
}
