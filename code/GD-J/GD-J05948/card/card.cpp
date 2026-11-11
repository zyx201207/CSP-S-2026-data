#include<iostream>
using namespace std;
int n,z,cnt=2,j=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	cin>>n>>z;
	int a[n+2],b[n+2],t[n+2];
	for(int i=1;i<=n;i++) cin>>a[i];
	while(1){
		for(int s=cnt-1;s<=n;s++){
			b[j]=a[s];
			for(int i=1;i<=j;i++){
				if(b[i]==b[j] && i!=j){
					for(int k=i+1;k<=j+1;k++) b[k]=0;
					j-=i+1;
					break;
				} 
			}
			j++;
		}
		j=1;
		for(int i=1;i<=cnt-1;i++){
			t[b[i]]++;
			b[i]=0;
		}
		cnt++;
		if(cnt==n+1) break;
	}
	for(int i=1;i<=z;i++) cout<<t[i]<<' ';
	return 0;
}
