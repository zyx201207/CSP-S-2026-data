#include<bits/stdc++.h>
using namespace std;
int n;char c[200000+10];long long dr,dl;
long long sum,a[200000+10],sr,sl;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}int i=1,j=n;
	for(;i<=j;){
		dr+=a[j];
		//cout<<1;
		dl=a[i];
		while(dr>=dl){
			//cout<<1;
			if(c[j]!=c[i])sum+=dl;
			dr-=dl;
			dl=a[i+1];
			i++;
		}
		j--;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
