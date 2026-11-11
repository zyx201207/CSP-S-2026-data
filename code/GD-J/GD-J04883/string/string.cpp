#include <bits/stdc++.h>
using namespace std;

struct Piece{
	int sum;
	char number;
};

Piece arr[200000];

int found(int x,int n){
	for(int i = 0;i < n;i++){
		if(x <= arr[i].sum){
			return i;
		}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	
	int count = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i].sum >> arr[i].number;
		count += arr[i].sum;
		arr[i].sum = count;
	}
	
	int ans = 0;
	for(int i = 1;i <= count / 2;i++){
		int p1 = found(i,n);
		int p2 = found(count - i + 1,n);
		if(arr[p1].number != arr[p2].number){
			ans++;
		}
	}
	
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
