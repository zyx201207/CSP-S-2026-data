#include<bits/stdc++.h>
using namespace std;
long long n;long long sum=0;
struct iii{
	long long q;char w;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
    	cin>>a[i].q>>a[i].w; 
	}
	for(int i=1,j=n;j>=1&&i<=n&&i<=j;++i){
		while(a[i].q>a[j].q){
			if(a[i].w!=a[j].w)sum+=a[j].q;
			a[i].q-=a[j].q;
			--j;
		}
		if(i==j)break;
		if(a[i].w!=a[j].w)sum+=a[i].q;
		a[j].q-=a[i].q;
	}
	cout<<sum;
	return 0;
} 
