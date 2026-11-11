#include<bits/stdc++.h>
using namespace std;
long long m,n,cards;
long long a[1000000],b[1000000],desk[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int o=i;o<=n;o++){
			desk[o]=a[o];
			cards=a[o];
			for(int p=i;p<=o-1;p++){
				if(desk[p]==cards){
					for(int l=p;l<=o-1;l++){
						desk[l]=0;
					}
				}
			}
		}
		for(int o=1;o<=m;o++){
			for(int p=i;p<=n;p++){
				if(desk[p]==o){
					b[o]+=1;
				}
			}
		}
		for(int o=1;o<=n;o++){
			desk[o]=0;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

