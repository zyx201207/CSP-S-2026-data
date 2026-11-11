#include<bits/stdc++.h>
using namespace std;

int a[500005],b[300005],c[500005],d[300005]={0};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1 ; i<=n ; i++) cin>>a[i];
	for (int i=1 ; i<=n ; i++){
		int q=0;
		for (int j=i ; j<=n ; j++){
			if (b[a[j]]>0){
				while (c[q]!=a[j]){
					b[c[q]]--;
					c[q]=0;
					q--;
				}
			}else{
				q++;
				c[q]=a[j];
				b[a[j]]++;
			}
		}
		for (int j=1 ; j<=q ; j++){
			d[c[j]]++;
			b[c[j]]--;
		}
	}
	for (int i=1 ; i<=m ; i++) cout << d[i] << ' ';
	return 0;
 } 
