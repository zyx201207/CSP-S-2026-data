#include<bits/stdc++.h>
using namespace std;
string shuzi[10000005],shuzi2[10000005];
long long nn[10000005];
string aa[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,no=0,no2=0;
	bool zimu=true;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nn[i]>>aa[i];
		string zi;
		zi=aa[0];
		if(zi!=aa[i]){
			zimu=false;
		}
	}
	if(zimu==true){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<nn[i];j++){
			shuzi[no]=aa[i];
			no++;
		}
	}
	while(no>=0){
		shuzi2[no2]=shuzi[no];
		no--;
		no2++;
	}
	bool noww=false;
	for(int i=0;i<no2;i++){
		if(shuzi[i]!=shuzi2[i]){
			noww=false;
			break;
		}
		noww=true;
	}
	long long sum=0;
	if(noww==true){
		cout<<0;
		return 0;
	}else{
		long long yiban=no2/2;
		for(int i=0;i<yiban;i++){
			if(shuzi[i]!=shuzi2[i]){
				sum++;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
