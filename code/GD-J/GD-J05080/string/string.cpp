#include<bits/stdc++.h>
using namespace std;
struct ko{
	long long k;
	char o;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long h;
	cin>>h;
	ko a[h+1]={};
	for(long long i=1;i<=h;i++){
		cin>>a[i].k>>a[i].o;
	} 
	long long cnt=0;
	for(long long i=1,j=h;i<j;){
		if(a[i].o==a[j].o){
			if(a[i].k>a[j].k){
				a[i].k-=(a[j].k);
				j--;
			}
			else if(a[i].k<a[j].k){
				a[j].k-=(a[i].k);
				i++;
			}
			else if(a[i].k==a[j].k){
				i++;
				j--;
			}
		}
		else{
			if(a[i].k>a[j].k){
				cnt+=(a[j].k);
				a[i].k-=(a[j].k);
				j--;
			}
			else if(a[i].k<a[j].k){
				cnt+=(a[i].k);
				a[j].k-=(a[i].k);
				i++;
			}
			else if(a[i].k==a[j].k){
				cnt+=(a[j].k);
				i++;
				j--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
