#include<bits/stdc++.h>
using namespace std;
long long n,mid,ma,sum = 0;
//int N = ;
char kun[1000010],num[10];
int x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int j=1;
	for(int i=1;i<=n;i++){
		cin >> x >> num[1];
		int k = j+x-1;//cout << k << " ";
		for(j;j<=k;++j){
			//cout << j <<" ";
			kun[j] = num[1];
		}//cout << endl;
	}j-=1;
	if(n%2==0){
		mid = j/2;
	}else{
		mid = j/2+1;
	}ma = j+1;//cout << j << " " << ma << " ";
	for(int i=1;i<=mid;i++){
		//cout << i << endl << ma-i << endl << kun[ma-i] << endl << kun[i] <<endl;
		if(kun[ma-i]!=kun[i]){
			sum++;
		}
	}cout << sum;
	return 0;
}

