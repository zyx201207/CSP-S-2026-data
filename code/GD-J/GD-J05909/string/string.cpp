#include <iostream>
#include <string>
using namespace std;

int hanshu(int L,int R,int M,int arr[],char arr1[],int change){
	if (L == M || R == M){
		if (arr1[L] != arr1[R]){
		if (arr[L] > arr[R]){
			arr[L] -= arr[R];
			change += arr[R];
			return change;
			}
		if (arr[L] < arr[R]){
			arr[R] -= arr[L];
			change += arr[L];
			return change;
			}
		if (arr[L] == arr[R]){
			change += arr[R];
			return change;
			}
		}
		if (arr1[L] == arr1[R]){
			return change;
			}
	}

	if (arr1[L] != arr1[R]){
		if (arr[L] > arr[R]){
			arr[L] -= arr[R];
			change += arr[R];
			return hanshu(L,R-1,M,arr,arr1,change);
		}
		if (arr[L] < arr[R]){
			arr[R] -= arr[L];
			change += arr[L];
			return hanshu(L+1,R,M,arr,arr1,change);
		}
		if (arr[L] == arr[R]){
			change += arr[R];
			return hanshu(L+1,R-1,M,arr,arr1,change);
		}
	}
	if (arr1[L] == arr1[R]){
		if (arr[L] > arr[R]){
			arr[L] -= arr[R];
			return hanshu(L,R-1,M,arr,arr1,change);
		}
		if (arr[L] < arr[R]){
			arr[R] -= arr[L];
			return hanshu(L+1,R,M,arr,arr1,change);
		}
		if (arr[L] == arr[R]){
			return hanshu(L+1,R-1,M,arr,arr1,change);
		}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	int arr[n];
	char arr1[n];
	for (int i = 0;i < n;i++){
		cin >>arr[i]>>arr1[i];
	}

	if (n < 2){
		cout <<0;
	}
	if (n == 2){
		if (arr1[0] == arr1[1]){
			cout <<0;
		}
		else{
			if (arr[0]>=arr[1]){
				cout <<arr[1];
			}
			else{
				cout <<arr[0];
			}
		}
	}
	if (n > 2){
		int num = 0;
		for (int i = 0;i < n;i++){
			num += arr[i];
		}
		if (arr[0] > (num/2)){
			int sum = 0;
			for (int i = 0;i < n;i++){
				if (arr1[i] == arr1[0]){
					sum += arr[i];
				}
				cout <<num-sum;
			}
		}
		if (arr[n-1] > (num/2)){
			int sum = 0;
			for (int i = 0;i < n;i++){
				if (arr1[i] == arr1[n-1]){
					sum += arr[i];
				}
				cout <<num-sum;
			}
		}
		else{
			int he=0;
			int L=0,R=n-1;
			int M;
			for (int i = 0;i < n;i++){	
				if (he <= num /2 && (he + arr[i+1]) >= num/2){
					M = i;
				}
				he += arr[i];
			}
			cout <<hanshu(L,R,M,arr,arr1,0);
		}
	}
	
	
	return 0;
}







