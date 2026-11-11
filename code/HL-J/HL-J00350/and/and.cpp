#include <iostream>
using namespace std;
int a[20015];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w"stdout);
	int n,m;
	cin>>n>>m;
	if(m==n){
		int s,a;
		cin>>s;
		for(int i=2;i<=n;i++){
			cin<<a;
			s=s&a;
		}
		cout<<s;
		return 0;
	}
	else if(m==1){
		int max=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max;
		return 0;
	}
	return 0;
} 
