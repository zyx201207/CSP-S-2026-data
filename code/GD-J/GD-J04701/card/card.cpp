#include<bits/stdc++.h>
using namespace std;
int tong1[30005],id[30005],tong2[30005],a[50005],b[50005];
int n,m,bl;
void change(int x){
	int i=1,j=1;
	while(a[i]!=x){
		b[j]=a[i];
		i++;
		j++;
	}
	i++;
	while(a[i]!=x){
		i++;
	}
	while(i<=n){
		b[j]=a[i];
		i++;
		j++;
	}
	bl=j;
	for(int i=1;i<=bl;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i]=a[i];
		}
		for(int j=i;j<=n;j++){
			tong1[a[j]]++;
			
			if(tong1[a[j]]>=2){
				tong1[a[j]]=1;
				change(a[j]);
			}
		}
		for(int j=i;j<=bl;j++){
			tong2[b[j]]++;
//			cout<<b[j]<<" ";
		}
		for(int j=1;j<=m;j++){
			tong1[j]=0;
		}	
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<tong2[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
