#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,sum;
	int ci=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int zong;
		zong=zong+x*10;
		for(int j=1;j<=x;j++){
			int s;
			cin>>s;
			s=s*10+s;
			num=num+s*10;
		}
		for(int f=1;f<=x;f++){
		
		cin>>sum;
			sum=sum+sum*10;
			num=sum+num;
		}
	}
	for(int v=1;v<=n;v++){
		if(num==sum){
			
		}
		ci++;
	}
	cout<<ci;
	return 0;
}
