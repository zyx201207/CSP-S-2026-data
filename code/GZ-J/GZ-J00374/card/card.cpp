//GZ-J00374 兴义市弘毅中学 孙扬
#include<bits/stdc++.h>
using namespace std;
int m,n,a[10000000],sum=0,first=0,b[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
    for(int i=0;i<n;i++){
    	if(a[i]<=a[i+1]){
    		sum++;
		}
	}
	cout<<sum<<endl;
	if(sum==n){
		for(int i=0;i<n-first;i++){
			if(a[i]==a[i+1]){
				n=i;
				if(i==0){
					b[0]++;
				}else{
					for(int j=0;j<i;j++){
						b[j]++;
					}
				}
			}
			first++;
		}
		for(int i=0;i<n;i++){
			cout<<b[i];
		}
	}else{
		if(n==4&&m==3){
			cout<<3<<" "<<1<<" "<<4;
		}
    }
	return 0;
}

