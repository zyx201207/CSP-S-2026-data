#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,h[300003],ans[300003];
int main(){
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==2){
		for(int i =1;i<=n;i++){
			ans[a[i]]++;
		}
		if(a[n] ==1)
			cout << n <<' '<<ans[2];
		if(a[n]==2)
			cout<<ans[1]<<' '<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(h[a[j]]){
				for(int k=h[a[j]]+1;k<j;k++){
					h[a[k]]=0;
				}
			}
			h[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(h[j])
				ans[j]++;
			h[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
hello!
it is the last year i join it,and maybe next year i will not join this
my english is pool
yep
*/
