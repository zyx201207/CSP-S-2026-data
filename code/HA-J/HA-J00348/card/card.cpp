#include <bits/stdc++.h>
using namespace std;
int n,m,a[200006],sl[3005],da[200006];
bool sf[3005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		sf[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			da[j]=a[j];
			for(int k=i;k<j;k++){
				if(da[k]==da[j]){
					for(int q=k;q<j;q++){
						da[q]=0;
//						cout<<k<<" "<<i<<" "<<j<<" ";
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
//			cout<<da[j]<<" ";
			sf[da[j]]=true;
		}
//		cout<<endl;
		for(int j=1;j<=m;j++){
			if(sf[j]){
				sl[j]++;
			}
			sf[j]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sl[i]<<" ";
	}
}
