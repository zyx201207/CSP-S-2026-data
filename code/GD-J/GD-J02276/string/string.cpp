#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
long long size, sum;
int n;
char c[250000];
long long a[250000];
ifstream In("string.in");
ofstream Out("string.out");
int main(){
	In >> n;
	for(int i = 0;i < n;i++){
		In >> a[i] >> c[i];
		size += a[i];
	}
	//从第一段往右边找对称
	long long whole = 0,offset = 0,leave,last = 0;//whole：当前量，offset：右侧偏移量，leave：衰减剩余量 	
	for(int i = 0;i < ceil(n / 2.0);i++) {
		leave = a[i];
		while(1){
			whole = a[n - offset - 1];//
			if(whole >= leave){
				if(c[i] != c[n - offset - 1]){
					sum += leave;
				}
				last = a[n - offset - 1] - a[i];
				break;
			}else{
				if(c[i] != c[n - offset - 1]){
					sum += a[n - offset - 1] + last;
//					cout << (int)(arr[0][n - offset - 1] - '0') << endl;
					leave -= a[n - offset - 1] - last;
					last = 0;
				}
			}
			offset++;
		}
	}
	Out << sum << endl;
	return 0;
}
