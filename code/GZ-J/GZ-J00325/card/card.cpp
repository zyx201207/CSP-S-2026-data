//GZ-J00325 遵义航天中学 李银涛 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int m,n;
	cin >> m >> n;
	long long c[m+1],c1[m+1],s[n+1],cnt[n+1];
	for(int i=1;i<=m;i++){
		cin >> c[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(c[i]==c[j]){
				c1[i]=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			s[j]=0;
		}
		for(int j=i;j<=m;){
			j=c1[j];
			s[c[j]]=1;
			j++;
		}
		for(int j=1;j<=n;j++){
			if(i==1){
				cnt[j]=0;
			}
			if(s[j]!=0){
				cnt[j]+=1;
			}
		}
		cout <<endl;
	}
	for(int i=1;i<=n;i++){
		cout << cnt[i] << " ";
	}
}
