#include <bits/stdc++.h>
using namespace std;
const int MAXX=100000000+5;
char o[MAXX];
int  p[MAXX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long ans=0;
	cin>>n;
	long long p[n];
	char o[n];
	for(long long i=0;i<n;i++){
		cin>>p[i]>>o[i];
	}
	long long z1=0;
	long long z2=n-1;
	for(long long i=0;i<n;i++){
		int er=0;
		if(p[z1]>p[z2]){
			er=1;
		}
		if(p[z1]==p[z2]){
			er=2;
		}
		if(o[z1]!=o[z2]){
			if(er==1)
			ans=ans+p[z2];
		else
			ans=ans+p[z1];
		}
		if(er==2){
			z1++;
			z2--;
		}
		else{
			if(er==1){
				p[z1]=p[z1]-p[z2];
				z2--;
			}
			else{
				p[z2]=p[z2]-p[z1];
				z1++;
			}	
		}
		if(z1>=z2)
		break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
