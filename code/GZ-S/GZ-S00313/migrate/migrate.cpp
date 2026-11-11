//遵义市新蒲新区滨湖中学 GZ-S00313 胡泽雨
#include <bits/stdc++.h>
using namespace std;

long long number,cnt,num,abl;
const long long N=2*1e6;
long long arr[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>number>>cnt;
	long long ans=0,c=4;
	for(int i=0;i<cnt;i++){
		cin>>num>>abl;
		for(int j=0;j<num;j++){
			cin>>arr[j];
		}sort(arr,arr+num);
			while(num>=c){
				int d=num-c+1;
				ans+=d;
				c+=2;
			}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}

