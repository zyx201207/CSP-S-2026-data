#include<bits/stdc++.h>
using namespace std;
struct WWW{
	long long shu;
	char f;
} a[200005];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i].shu>>a[i].f;
	}
	long long i=0,j=n-1;
	while(i<j){
		if(a[i].f!=a[j].f){
			long long c=min(a[i].shu,a[j].shu);
			sum+=c;
			//cout<<sum<<" "<<i<<" "<<j<<endl;
			a[i].shu-=c;
			a[j].shu-=c;
			if(a[i].shu<=0){
				i++;
			}
			if(a[j].shu<=0){
				j--;
			}
		}else if(a[i].f==a[j].f){
			long long c=min(a[i].shu,a[j].shu);
			a[i].shu-=c;
			a[j].shu-=c;
			if(a[i].shu<=0){
				i++;
			}
			if(a[j].shu<=0){
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
