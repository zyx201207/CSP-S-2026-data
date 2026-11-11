#include<iostream>
using namespace std;
long long n;
long long k[200005];
long long z1;
long long y1;
long long ans;
long long sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		sum+=k[i];
		cin>>c[i];
	}
	y1=1;
	z1=1;
	int y2=k[n];
	int z2=n;
	for(int i=1;i<=sum/2;i+=2){
		if(c[z1]!=c[z2]){
			ans++;
		}
		y1++;
		y2--;
		if(y1==k[z1]+1){
			y1=1;
			z1++;
		}
		if(y2==k[z2]+1){
			y2=1;
			z2++;
		}
		if(c[z1]!=c[z2]){
			ans++;
		}
		y1++;
		y2--;
		if(y1==k[z1]+1){
			y1=1;
			z1++;
		}
		if(y2==k[z2]+1){
			y2=1;
			z2++;
		}
	}
	cout<<ans;
	return 0;
}
