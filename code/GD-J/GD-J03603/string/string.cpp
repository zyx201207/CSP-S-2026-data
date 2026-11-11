#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c,d,p,q;
char b[200005],e;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}p=1;
	q=n;
	while(p<q){
		if(b[p]!=b[q]){
			if(a[p]>a[q]){
				c+=a[q];
				a[p]=a[p]-a[q];
				q--;
			}else if(a[p]<a[q]){
				c+=a[p];
				a[q]=a[q]-a[p];
				p++;
			}else{
				c+=a[p];
				p++;
				q--;
			}
		}else{
			if(a[p]>a[q]){
				a[p]=a[p]-a[q];
				q--;
			}else if(a[p]<a[q]){
				a[q]=a[q]-a[p];
				p++;
			}else{
				p++;
				q--;
			}
		}		
	}cout<<c;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
