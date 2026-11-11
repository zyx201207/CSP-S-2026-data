#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

struct node{
	int num;
	char chara;
} arr[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> arr[i].num >>arr[i].	chara;
	}
	int l=1,r=n;
	long long sum=0;
	while(1){
		if(arr[l].num == 0){
			l++;
		}
		if(arr[r].num == 0){
			r--;
		}
		if(arr[l].chara == arr[r].chara){
			int mm=min(arr[l].num,arr[r].num);
			arr[l].num -= mm;
			arr[r].num -= mm;
		}else{
			sum += min(arr[l].num,arr[r].num);
			int mm=min(arr[l].num,arr[r].num);
			arr[l].num -= mm;
			arr[r].num -= mm;	
		}
		
		if(l >=r ){
			break;
		} 
	}
	cout << sum;
	return  0;
} 
