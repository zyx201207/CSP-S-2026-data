#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans[1000005],b[1000005],l[1000005],cnt,lst;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=lst;j++){
			b[j]=0;
		} 
		cnt=lst=0;
		for(int j=i;j<=n;j++){
			l[a[j]]=b[j-i+1]=0;
		}
		for(int j=i;j<=n;j++){
			if(l[a[j]]&&l[a[j]]<cnt&&b[l[a[j]]]==a[j]){
				cnt=l[a[j]];
			}else{
				b[++cnt]=a[j];
				l[a[j]]=cnt;
			}
			lst=max(lst,cnt);
			/*
			for(int k=1;k<=cnt;k++){
				cout<<b[k]<<' ';
			}
			cout<<endl;
			*/
		}
		for(int j=1;j<=cnt;j++){
			ans[b[j]]++;
			//cout<<b[j]<<' ';
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
