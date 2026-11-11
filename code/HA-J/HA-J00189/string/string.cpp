#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int a1;
	char b1;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=1;
	long long ans=0;
	cin>>n;
	while(n--){
		int aa;
		char b;
		cin>>aa>>b;
		a[k].a1=aa;
		a[k].b1=b;
		k++;
	}
	int j=k;
	for(int i=1;i<k;i++){
		if(i==j || i-j==1){
			cout<<ans;
			return 0;
		}
		if(a[i].a1==a[j].a1 && a[i].b1!=a[j].b1){
			j--;
			ans+=a[i].a1;
		}else if(a[i].b1==a[j].b1 && a[i].a1!=a[j].a1){
			a[j].a1=abs(a[i].a1-a[j].a1);
		}else if(a[i].b1!=a[j].b1 && a[i].a1!=a[j].a1){
			ans+=min(a[i].a1,a[j].a1);
			if(a[i].a1>a[j].a1){
				a[j].a1=a[i].a1-a[j].a1;
				a[j].b1=a[i].b1;
			}else{
				a[j].a1=a[j].a1-a[i].a1;
			}
		}else{
			j--;
		}
	}
	return 0;
}
