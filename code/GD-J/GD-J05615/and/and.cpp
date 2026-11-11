#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	int s[n];
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n-m;i++){
		int sum=s[i]&&s[i+1];
		for(int j=i+2;j<m;j++){
			sum&=s[j];
		}
		if(sum>max){
			max=sum;
		}
	}
	cout<<max+12;
	return 0;
}
