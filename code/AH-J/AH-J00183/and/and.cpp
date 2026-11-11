#include<bits/stdc++.h>
using namespace std;
int a[200010],b[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==2){
		int cnt=-1,x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=a[i]&a[j];
				cnt=max(cnt,x);
			}
		}
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==3){
		int k=0,x=0,cnt=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				k++;
				x=a[i]&a[j];
				b[k]=x;
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				x=b[i]&a[j];
				cnt=max(cnt,x);
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
