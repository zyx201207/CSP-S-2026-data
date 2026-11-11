#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n+1]{},q=1,w=n;
	char b[n+1]{};
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(1){
		if(q==w)break;
		if(b[q]!=b[w]){
			cnt+=min(a[q],a[w]);
		}
		if(a[q]>=a[w]){
				a[q]=a[q]-a[w],a[w]=0,w-=1;	
		}else {
				a[w]=a[w]-a[q],a[q]=0,q+=1;	
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
