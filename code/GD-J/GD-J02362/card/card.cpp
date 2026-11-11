#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],ans[300005],b[500005],cnt;
int main(){
	//freopen("card.in","r","stdin");
	//freopen("card.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=n;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=cnt;k++){
				if(a[j]==b[k]){
					for(int l=k+1;l<=cnt;l++)b[k]=0;
					cnt=k;
					break;
				}
				else{
					b[++cnt]=a[j];
				}
			}
			for(int k=1;k<=cnt;k++)ans[b[k]]++;
		}
		for(int i=1;i<=n;i++)b[i]=a[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
