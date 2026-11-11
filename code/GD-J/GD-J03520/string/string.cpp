#include<bits/stdc++.h>
using namespace std;
long long n,sum;
bool l;
struct A{
	long long s;
	char g;
}a[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].g;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].g!=a[j].g){
			if(a[i].s<a[j].s&&l==false){
				sum=sum+a[i].s;
				a[j].s-=a[i].s;
				i++;
				l=true;
			}
			if(a[i].s==a[j].s&&l==false){
				sum=sum+a[i].s;
				a[i].s=0;a[j].s=0;
				i++;j--;
				l=true;
			}
			if(a[i].s>a[j].s&&l==false){
				sum=sum+a[j].s;
				a[i].s-=a[j].s;
				j--;
				l=true;
			}
			l=false;
		}
		else{
			if(a[i].s<a[j].s&&l==false){
				a[j].s-=a[i].s;
				i++;
				l=true;
			}
			if(a[i].s==a[j].s&&l==false){
				a[i].s=0;a[j].s=0;
				i++;j--;
				l=true;
			}
			if(a[i].s>a[j].s&&l==false){
				a[i].s-=a[j].s;
				j--;
				l=true;
			}
			l=false;
		}
	}
	cout<<sum;
	return 0;
}
