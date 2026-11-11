#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],anss[500005],ans[500005],num=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(ans,0,sizeof(ans));
		num=0;
		for(int j=i;j<=n;j++){
			if(t[a[j]]>0){
				int num2=num;
				num=t[a[j]];
				for(int k=t[a[j]];k<=num2;k++){
					ans[k]=0;
					t[ans[k]]=0;
				}
				ans[num]=a[j];
				t[a[j]]=num;
			}
			if(t[a[j]]==0){
				num++;
				t[a[j]]=num;
				ans[num]=a[j];
			}
		}
		for(int k=1;k<=num;k++){
			anss[ans[k]]++;
		}
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++){
		cout<<anss[i]<<' ';
	}
	return 0;
}
