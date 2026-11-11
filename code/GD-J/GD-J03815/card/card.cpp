#include<iostream>
#include<cstring>
using namespace std;
int q[1000000];
int tail=-1,front=0;
int count[1000000];
int ans[1000000];
int a[1000000];
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(count,-1,sizeof(count));
//		if(count[0]!=-1||count[1]!=-1)throw("memset is useless");
		for(int j=i;j<n;j++){
			if(count[a[j]]==-1)count[a[j]]=tail+1;
			else {
				for(int f=count[a[j]];f<=tail;f++){
					count[a[f]]=-1;
				}
				tail=count[a[j]]-1;
				count[a[j]]=tail+1;
			}
			q[++tail]=a[j];
			count[a[j]]=tail+1;
		}
//		for(int j=1;j<=m;j++){
//			cout<<count[j]<<' ';
//		}
//		cout<<endl;
		for(int j=1;j<=m;j++){
			if(count[j]!=-1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
