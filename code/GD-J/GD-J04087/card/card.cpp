#include <bits/c++.h>
using namespace std;
long long b[500009],z[500009];
int main(){

	freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
long long n,m,a[500009],c=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	
}
for(int i=1;i<=n;i++){
	for(int j=i;i<=m;j++){
		for(int q=i;q<=j;j++){
			if(a[j]==a[q]){
				c=q;
				break;
			}
			if(c==0){
			b[j]=a[j];
			}
			else{
				for(int w=c;w<=j;w++){
					b[w]=0;
				}
				b[q]=a[j];
			}
			
		}
	}
	for(int s=i;s<=m;s++){
		z[b[s]]++;
	}
}
for(int i=1;i<=m;i++){
	cout<<z[i]<<" ";
}
return 0;}
