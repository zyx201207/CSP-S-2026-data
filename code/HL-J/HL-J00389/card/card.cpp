#include<bits/stdc++.h>
using namespace std;
int a[500005],num[500005],ans[500005];
struct node{
	int number;
	int pl;
}f[500005];
string s;
int n,m,id;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	id=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]].number==0){
				f[a[j]].number=1;
				f[a[j]].pl=id;
				num[id]=a[j];
				id+=1;
			}
			if(f[a[j]].number!=0){
				for(int k=f[a[j]].pl+1;k<=id-1;k++){
					num[k]=0;
				}
				id=f[a[j]].pl+1;
			}
		}
		for(int j=1;j<=id-1;j++){
			ans[num[j]]++;
		}
		id=1;
		memset(f,sizeof(f),0);
		memset(num,sizeof(num),0);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
