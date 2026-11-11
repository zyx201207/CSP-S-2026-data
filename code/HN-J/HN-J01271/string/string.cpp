#include<bits/stdc++.h>
using namespace std;
struct x{
	long long shu;
	char ch;
}a[200010];
long long n,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu>>a[i].ch;
	}
	int i=1,j=n;
	while(i<j){
		if(a[i].ch!=a[j].ch){
			if(a[i].shu>a[j].shu){
				a[i].shu-=a[j].shu;
				sum+=a[j].shu;
				j--;
			}else if(a[i].shu<a[j].shu){
				a[j].shu-=a[i].shu;
				sum+=a[i].shu;
				i++;
			}else if(a[i].shu==a[j].shu){
				sum+=a[j].shu;
				i++;
				j--;
			}
		}else{
			if(a[i].shu>a[j].shu){
				a[i].shu-=a[j].shu;
				j--;
			}else if(a[i].shu<a[j].shu){
				a[j].shu-=a[i].shu;
				i++;
			}else if(a[i].shu==a[j].shu){
				i++;
				j--;
			}
		}
	}cout<<sum;
	return 0;
} 
