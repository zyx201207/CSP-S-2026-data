#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long ans;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		cin >>c[i];
	}
	int i=1,j=n;
	while(j>i){
		bool km=(a[i]>a[j]),kn=(c[i]==c[j]);
		if(km){
			if(kn){
				a[i]-=a[j];
				j--;
				continue;
			}
			ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		else{
			if(a[i]==a[j]){
				if(kn){
					j--;
					i++;
					continue;
				}
				ans+=a[j];
				i++;
				j--;
			}
			else{
				if(kn){
				a[j]-=a[i];
				i++;
				continue;
			}
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout <<ans;
	return 0;
} 
