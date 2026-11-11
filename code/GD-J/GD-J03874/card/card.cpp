#include<iostream>
using namespace std;
int n;
int m;
int a[1000000];
int t[1000000];
int v[1000000];
int sum;
int u[1000000];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t[1000000];
		for(int j=1;j<=n;j++){
			t[j]=0;
		}
		int v[1000000];
		sum=0;
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0){
				for(int x=t[a[j]];x<=j;x++){
					t[x]=0;
					v[x]=0;
				}
			}
			t[a[j]]=j;
			v[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			sum=sum+v[j];
		}
		u[sum]++;
	}
	for(int i=1;i<=m;i++){
		cout<<u[i]<<" ";
	}
	return 0;
}
