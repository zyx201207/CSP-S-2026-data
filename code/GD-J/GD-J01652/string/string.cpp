#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s[MAXN];
	long long a[MAXN];
	long long ans=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int q=n-1;
	for(int p=0;p<n;p++){
		while(a[p]>0){
			if(s[p]!=s[q]){
				if(a[p]<a[q]) {
					ans+=a[p];
					s[p]=s[q];
					a[q]=a[q]-a[p];
					a[p]=0;
				}else if(a[p]>a[q]) {
					ans+=a[q];
					s[q]=s[p];
					a[p]=a[p]-a[q];
					a[q]=0;
					q--;
				}else if(a[p]==a[q]){
					ans+=a[q];
					s[q]=s[p];
					a[q]=0;
					a[p]=0;
					q--;
				}
			}else if(s[p]==s[q]){
				if(a[p]<a[q]) {
					a[q]=a[q]-a[p];
					a[p]=0;
				}else if(a[p]>a[q]) {
					a[p]=a[p]-a[q];
					a[q]=0;
					q--;
				}else if(a[p]==a[q]){
					a[q]=0;
					a[p]=0;
					q--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
