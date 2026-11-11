#include<bits/stdc++.h>
using namespace std;

const int N=5e5+3,M=3e5+3;
int n,a[N],m,b[M];
int l[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l[j]=0;
		}
		for(int j=i;j<=n;j++){
			l[j]=a[j];
			for(int k=i;k<j;k++){
				if(l[k]==a[j]){
					for(int q=k;q<j;q++){
						l[q]=0;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(l[j]!=0){
				b[l[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
