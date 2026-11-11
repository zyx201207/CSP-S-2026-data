#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[100005];
long long k,cnt=0;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
		cin>>c[i];
		}
		k=a[n]/2;
		int cn=1;
		int cnn=n;
		for(int i=1;i<=k;i++){
			if(a[cn]>=i){
				if(a[cnn-1]<a[n]+1-i){
						if(c[cnn]!=c[cn]){
							cnt++;
						}
					}
					else{
						cnn--;
						i--;
					}
			}else{
				cn++;
				i--;
			}
		}
		cout<<cnt;
	return 0;
}
