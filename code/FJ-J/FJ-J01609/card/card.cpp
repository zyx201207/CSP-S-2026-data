#include<iostream>
using namespace std;
int a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int f=1;f<=500005;f++){
			if(c[f]==0){
				break;
			}
			c[f]=0;
		}
		for(int j=i;j<=n;j++){
			int p;
			for(int f=1;f<=500005;f++){
				if (c[f]==a[j]){
					for(int g=f;g<=500005;g++){
						if(c[g]==0){
							p=f;
							break;
						}else{
							c[g]=0;
						}
					}
					break;
				}
				if(c[f]==0){
					p=f;
					break;
				}
			}
			c[p]=a[j];
		}
		for(int f=1;f<=500005;f++){
			if(c[f]==0){
				break;
			}else{
				b[c[f]]++; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
