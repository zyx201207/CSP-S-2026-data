#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char o[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>o[i];
	}
	long long last=n;
	int i=1;
	while(true){
		if(last==i) break;
		if(o[i]==o[last]){
			if(a[i]>a[last]){
				a[i]-=a[last];
				a[last]--;
			}
			else{
				a[last]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[last]){
				num+=a[last];
				a[i]-=a[last];
				last--;
			}
			else{
				num+=a[i];
				a[last]-=a[i];
				i++;
			}
		}
	}
	cout<<num;
	return 0;
}
