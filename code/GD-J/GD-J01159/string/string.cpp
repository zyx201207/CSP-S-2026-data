#include<bits/stdc++.h>
using namespace std;
long long n,l=0;
long long a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				l+=a[j];
				j--;
				a[i]=a[i]-a[j];
			}if(a[i]==a[j]){
				l+=a[i];
				j--;
				i++;
			}if(a[i]<a[j]){
				l+=a[i];
				i++;
				a[j]=a[j]-a[i];
			}
		}if(c[i]==c[j]){
			if(a[i]>a[j]){
				j--;
				a[i]=a[i]-a[j];
			}if(a[i]==a[j]){
				j--;
				i++;
			}if(a[i]<a[j]){
				i++;
				a[j]=a[j]-a[i];
			}
		}
	}cout<<l;
    return 0;
}