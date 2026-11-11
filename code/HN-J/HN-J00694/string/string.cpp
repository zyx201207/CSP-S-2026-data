#include<bits/stdc++.h>
using namespace std;
char b[200001],a1[200001];
long long a[200001]={0},sum,mid=0,wes=1,wes2,z1=0,z2=0,da=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,q=0,bj=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	mid=sum/2;
	if(sum%2==1){
		wes2=n;
		for(int i=1,j=sum;z1<=mid,z2<=mid;i++,j--){
			if(i>a[wes]){
				i=1;
				wes++;
			}
			if(j>a[wes2]){
				j=1;
				wes2--;
			}
			if(b[wes]!=b[wes2]){
				da++;
			}
			z1++;
			z2++;
		}
	}else{
		wes2=n;
		for(int i=1,j=sum;z1<=mid,z2<=mid;i++,j--){
			if(i>a[wes]){
				i=1;
				wes++;
			}
			if(j>a[wes2]){
				j=1;
				wes2--;
			}
			if(b[wes]!=b[wes2]){
				da++;
			}
			z1++;
			z2++;
		}
	}
	cout<<da;
	return 0;
}
