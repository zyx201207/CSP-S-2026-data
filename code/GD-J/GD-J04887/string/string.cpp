#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	long long y;
};
int n;
int num[200001];
char b[200001];
long long cnt = 0;
node a[200001];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long x = 1 , y;
	for(int i = 1; i <= n; i++){
		cin >> num[i] >> b[i];
		y = x + num[i] -1;
		a[i].x = x ;
		a[i].y = y;
		x = y + 1;
	}
	long long left=1,right=y; 
	int q1 = 1; // 当前区间 
	int q2 = n;
	while(left < right){
		if(b[q1] != b[q2]){
			cnt++;
		}
		left++;
		right--;
		//更新区间
		
		if(!(left >= a[q1].x && left <= a[q1].y)) {
			q1++;
		}
		if(!(right >= a[q2].x && right <= a[q2].y)){
			q2--;
		}
	}
	cout << cnt;
	return 0;
}
