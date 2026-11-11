#include<bits/stdc++.h>
using namespace std;
long long n,shu,cnt;
struct san{
	long long int num;
	char s;
}a[100000086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
	}
	long long i=1;
	while(i<n){
		if(a[i].s!=a[n].s){
			cnt+=min(a[i].num,a[n].num);
			if(a[i].num<a[n].num){
				a[n].num-=a[i].num;
				i++;
			}else if(a[i].num>a[n].num){
				a[i].num-=a[n].num;
				n--;
			}else{
				i++;
				n--;
			}
		}else{
			if(a[i].num<a[n].num){
				a[n].num-=a[i].num;
				i++;
			}else if(a[i].num>a[n].num){
				a[i].num-=a[n].num;
				n--;
			}else{
				i++;
				n--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
		

