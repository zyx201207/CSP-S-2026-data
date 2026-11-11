#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],e[300005],v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[500005];
		for(int j=i+1;j<=n;j++){
			for(int q=i;q<=n;q++){
				b[q]=a[q];
				e[a[q]]++;
				if(e[a[q]]>1){
					int b[500005];
					b[1]=a[q];
					e[a[q]]--;
				}
				
			}
			for(int o=1;o<=m;o++){
				v[b[o]]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<v[i];
	return 0;
}
