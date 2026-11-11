#include<iostream>
using namespace std;
int a[500000];
bool b[500000];
int c[500000]={0};
int main(){
	int n,m;
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<i;j++){
			if(a[i]==a[j]&&b[j]==0){
				for(int k=j;k<i;k++){
					b[k]=1;
				}
				j=i;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(b[i]==0)c[a[i]]++;
		b[i]=0;
		
	}
	int s=1;
	while(s<n){
		for(int i=s;i<n;i++){
			for(int j=s;j<i;j++){
				if(a[i]==a[j]&&b[j]==0){
					for(int k=j;k<i;k++){
					b[k]=1;
					}
					j=i;
				}
			}
		}
		for(int i=s;i<n;i++){
			if(b[i]==0)c[a[i]]++;
			b[i]=0;
			
		}
		s++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
