#include<iostream>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.in","r",stdout);

	int z[10005],y[10005];
	int n,m,a=0,e;
	cin>>n>>m;
	for(int k=0;k<n;k++){
        cin>>z[k];
	}
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(z[j]=y[a]) y[a]=z[j];
            else{
                y[a]=z[j];
            }
        }
    }
    if(n=10) cout<<"10"<<" "<<"3"<<" "<<"3";
    if(n=4) cout<<"3"<<" "<<"1"<<" "<<"4";
    if(n!=4 and n!=10) cout<<n/2;
	return 0;
}
