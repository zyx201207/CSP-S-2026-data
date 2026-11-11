#include<bits/stdc++.h>
using namespace std;
struct dog{
	int s;
	char b;
}a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].b;
	}
	int j=n;
	for(int i=1;i<j;i+=0){
		if(a[i].b!=a[j].b){
			if(a[i].s>a[j].s){
				a[i].s=a[i].s-a[j].s;
				cnt+=a[j].s;
				j--;
			}
			else if(a[i].s<a[j].s){
				a[j].s=a[j].s-a[i].s;
				cnt+=a[i].s;
				i++;
			}
			else if(a[i].s==a[j].s){
				cnt+=a[j].s;
				i++;
				j--;

			}
		}else{
			if(a[i].s>a[j].s){
				a[i].s=a[i].s-a[j].s;
				j--;
			}
			else if(a[i].s<a[j].s){
				a[j].s=a[j].s-a[i].s;
				i++;
			}
			else if(a[i].s==a[j].s){
				i++;
				j--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
