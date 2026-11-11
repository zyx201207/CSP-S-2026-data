#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt[500005],vis[500005],sum,zong;
bool ans[500005];
void fin(int x,int y){
	for(int i=x;i<x+y;i++)b[i]=a[i];
	return;
}
void fsort(int x,int y){
	int uoi=b[x];
	for(int i=x+1;i<x+y;i++){
		if(b[i]<uoi)b[i-1]=b[i];
		else{
			b[i-1]=uoi;
			break;
		}
	}
	return;
}
void fshou(int x,int y){
	for(int i=x;i<x+y;i++){
		int de=0;
		int uoi=b[i];
		for(int j=x;j<x+y;j++){
			if(b[j]==uoi)de++;
		}
		zong=max(zong,de);
	}
	return;
}
void ftan(int x,int y,int t){
	while(t>0){
		b[x]+=1;
		fsort(x,y);
		fshou(x,y);
		t--;
	}
	return;
}
void fout(int x,int y){
	for(int i=x;i<x+y;i++)b[i]=0;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cnt[i]=a[i]+m;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[i]<a[j]){
				vis[i]=j-i;
				break;
			}
		}
		if(cnt[i]>=a[n])vis[i]=n-i+1;
		sum=max(sum,vis[i]);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==sum)ans[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==1){
			fin(i,vis[i]);
			ftan(i,vis[i],m);
			fout(i,vis[i]);
		}
	}
	cout<<zong;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
