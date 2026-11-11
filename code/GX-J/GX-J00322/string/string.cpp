#include<bits/stdc++.h>
using namespace std;
int n,b[200010];
char a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		b[i]=x;
		a[i]=y;
	}
	long long sum=0;
	int i=1,j=n;
	for(;;){
		if(a[i]==a[j]){
			if(b[i]==b[j]){
				i++;
				j--;
			}else if(b[i]>b[j]){
				b[i]-=b[j];
				j--;
			}else{
				b[j]-=b[i];
				i++;
			}
		}else{
			if(b[i]==b[j]){
				sum+=b[i];
				j--;
				i++;
			}else if(b[i]>b[j]){
				sum+=b[j];
				b[i]-=b[j];
				j--;
			}else{
				sum+=b[i];
				b[j]-=b[i];
				i++;
			}
		}
		if(i==j){
			break;
		}
	}
	cout<<sum;
	return 0;
}
