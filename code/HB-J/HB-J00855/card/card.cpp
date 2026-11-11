#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int n,m;
	bool flag=1;
	int a[500005],b[500005];
	cin>>n>>m;
	int ans[m+5];
	
	for(int j=1;j<=n;j++)cin>>a[j];
	for(int i=1;i<=m;i++){
		int bed=1;
		for(int j=i;j<=n;j++){
			b[bed]=a[j];
			bed++;
			for(int k=1;k<bed-1;k++)
				if(b[k]==b[bed-1]){for(int g=k;g<=bed-1;g++)b[g]=0;bed=k;flag=0;break;}
			if(flag==1)bed++;
		}
		for(
	return 0;
}
