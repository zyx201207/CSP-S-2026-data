#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],s[300005],q,z[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		q=i-1;
		for(int j=i;j<=n;j++){
			b[j-q]=a[j];
			s[a[j]]++;
			if(s[a[j]]>1){
				b[j-q]=0;
				q++;
				for(int k=j-1;b[k]!=a[j];k--){
					s[b[k]]--;
					b[k]=0;
					q++;
				}
				b[j-q]=a[j];
				s[a[j]]++;
			}
		}
		for(int j=i;j<=m;j++){
			z[j]+=s[j];
			s[j]=0;
		}
	}
	z[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0;
}
