#include<iostream>
using namespace std;
int n,m,a[1000001],b[1000001],c[1000001];
bool pd[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			pd[i]=1;
		}
		for(int j=i;j<=n;j++){
			if(pd[a[j]]){
				cout<<"i:"<<i<<" a[j]:"<<a[j]<<endl;
				b[a[j]]++;
				pd[a[j]]=0;
			}
			if(!pd[a[j]]){
				for(int w=i;w<=j-1;w++){
					b[a[w]]--;
					pd[a[w]]=1;
				}
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
