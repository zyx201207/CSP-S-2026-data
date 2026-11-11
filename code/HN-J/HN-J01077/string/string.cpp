#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,q=1,f=0;
	cin>>n;
	int a[n+1];
	a[0]=1;
	char c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];  
		f+=a[i];
	} 
	char b[f+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[q]=c[i];
			q++;
		}
		
	}
	for(int i=1;i<=strlen(b)/2;i++){
		if (i<f){
		
			if(b[i]!=b[f]){
				b[f]=b[i];
				
				s++;
			}
		f--;}
	} 
	cout<<s;
	return 0;
}
