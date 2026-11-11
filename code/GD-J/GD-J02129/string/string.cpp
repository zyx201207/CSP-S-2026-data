#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int num,num2,num3;
long long ls;
char lc1,lc2;
struct no{
	int nu;
	char ch;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].nu>>a[i].ch;
	}
	if(n%2==1)n++;
	for(int i=1;i<=n/2;i++){
		if(a[i].nu+num2>a[n-i+1].nu+num3){
		num2=a[i].nu+num2-a[n-i+1].nu+num3;
		lc1=a[i].ch;
			if(a[i].ch!=a[n-i+1].ch){
				ls+=a[n-i+1].nu+num3;
				num3=0;
			}
			else{
				ls+=a[n-i+1].nu+num3-min(a[i].nu+num2-a[n-i+1].nu+num3,a[n-i+1].nu);
				num3=0;
			}
		}
		else if(a[i].nu+num2<a[n-i+1].nu+num3){
		num3=a[n-i+1].nu+num3-a[i].nu+num2;
		lc2=a[n-i+1].ch;
			if(a[i].ch!=a[n-i+1].ch){
				ls+=a[i].nu+num2;
				num2=0;
			}
			else{
				ls+=a[i].nu+num2-min(a[n-i+1].nu+num3-a[i].nu+num2,a[i].nu);
				num2=0;
			}
		}
		else{
			if(a[i].ch!=a[n-i+1].ch){
				ls+=a[i].nu+num2;
			}
			else{
				ls+=a[i].nu+num2-min(a[i].nu,a[n-i+1].nu);
				num2=0;
			}
			num2=0;
			num3=0;
			
		}
	}
	cout<<ls;
	return 0;
}
