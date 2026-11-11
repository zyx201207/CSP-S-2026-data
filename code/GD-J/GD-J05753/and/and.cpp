#include<Bits/stdc++.h>
using namespace std;
int a,b,c[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int j = 0;j < a;j++){
		cin>>c[j];
	}
	sort(c,c + a);
	if(b == 1){
		cout<<c[a - 1];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(b == a){
		int sum = c[0];
		for(int j = 1;j < a;j++){
			sum = sum & c[j];
		}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(b == 2){
		int sum = INT_MIN;
		for(int j = 0;j < a;j++){
			for(int x = 0;x < a;x++){
				sum = max(sum,c[j] & c[x]);
			}
		}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int sum = c[a - 1];
	for(int j = a - 2;j >= a - b;j--){ 
		sum = sum & c[j];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
