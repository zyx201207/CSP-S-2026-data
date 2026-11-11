#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	char x[200000005],z[200000005];
	long long k=0;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		scanf("%lld",&a);
		cin>>c;
		if(k<200000005){	
			for(int j=0;j<a;j++){
				x[k]=c;
				k++;
			}
		}else{
			for(int j=0;j<a;j++){
				x[k-200000005]=c;
				k++;
			}
		}
	}
	long long y=0;
	for(int i=0;i<k/2;i++){
		if((x[i]!=x[k-i-1]&&k-i-1<200000005)||(k-i-1>=200000005&&x[i]!=z[k-i-1-200000005])){
			y++;
		}
	}
	printf("%lld",y);
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
