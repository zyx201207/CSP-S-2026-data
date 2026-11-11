#include<iostream>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.in","r",stdout);

	long long z[200000005],y[200000005];
	int n,m,a=0,e;
	cin>>n>>m;
	for(int p=0;p<n;p++){
        cin>>z[p];
	}
	for(int i=0;i<n;i++){
        y[i]=z[i];
	}
	for(int j=0;j<n;j++){
        for(int k=j;k>0;k--){
            if(z[k]<z[k-1]){
                e=z[k];
                z[k]=z[k-1];
                z[k-1]=e;
            }
            else{
                break;
            }
        }
	}
	cout<<z[2];


	return 0;
}
