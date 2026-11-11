#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0,j;i<n;i++){
		int flag=0,shu=n;
		for(j=i+1;j<n;j++){
			if(b[i]==a[j]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			shu++;
			a[shu]=b[i];
		}else{
			for(;j>=0;j--){
				c[j]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
