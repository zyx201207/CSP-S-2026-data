#include<iostream>
#include<cstring>

using namespace std;


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	long long num[100000];
	cin>>a>>b;
	for(int i = 0;i<a;i++){
		long long y;
		cin>>y;
		num[i] = y;
	}
	for(int i = 0;i<a;i++){
		for(int j = 0;j<a-1;j++){
			if(num[j]<num[j+1]){
				int e = num[j];
				num[j] = num[j+1];
				num[j+1] = e;
			}
		}
	}
	long long flag = num[0];
	for(int i = 0;i<b;i++){
		if(flag>num[i]){
			flag = num[i];
		}
	}
	cout<<flag;
	return 0;
}
